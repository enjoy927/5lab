#include <iostream>
#include <fstream>
#include "CLink.h"
#include "cWork.h"

class CWorkspace {
public:
	CWorkspace(CDataChain &data): m_refChain(data) {}
	//~CWorkspace(void) {}
	//Ініціалізує повну послідовність цифр
	void Init(int nDepth, int nLength) {
		m_refChain.Generate(nDepth, nLength);
	}

	//Повертає стрічку із повною послідовністю цифр.
	const char *GetChainString() {
		return m_refChain.GetFullString();
	}

	bool Save(std::string &sFilePath) {
		if (sFilePath == "")
			return false;

		std::string save = GetChainString();
		std::ofstream saveFile(sFilePath, std::fstream::app);

		saveFile << size(save)-1 << std::endl;
		saveFile << GetChainString() << std::endl;

		saveFile << m_aLinks.size() << std::endl;
		for (int i = 0; i < m_aLinks.size(); i++) {
			m_aLinks[i]->Save(saveFile);
		}
		
		saveFile.close();

		return true;
	}

	bool Load(std::string &sFilePath) {
		std::ifstream loadFile(sFilePath);
		
		if (!loadFile.is_open())
			return false;
		
		std::string str, resultStr;
		int i = 0, fCheck = -1;
		while (std::getline(loadFile, str)) {
			if (i == 0) {
				i++;
				continue;
			}

			if (str == "") {
				// i + 1 - рядок із кількістю links
				fCheck = i + 1;
			}

			if (i == fCheck) {
				int end = stoi(str);
				for (int j = 0; j < end; j++) {
					AddLink(-1, -1, new CLink(m_refChain));
					m_aLinks[m_aLinks.size() - 1]->Load(loadFile);
				}

				break;
			}


			m_refChain.SetM_sChain(m_refChain.GetFullString() + str);
			i++;
		}

		loadFile.close();

		return true;
	}

	int Find(const char *sSubStr, int nPos = 0) {
		return m_refChain.Find(sSubStr, nPos);
	}

	bool AddLink(int nStartPos, int nLength, CLink* pLink) {
		pLink->SetM_nPos(nStartPos);
		pLink->SetM_nSize(nLength);

		m_aLinks.push_back(pLink);
		return true;
	}

	bool RemoveLink(int nPosInList) {
		if (nPosInList < 0 || nPosInList >= m_aLinks.size()) {
			std::cout << "Error no such element with this id in list";
			return false;
		}

		m_aLinks.erase(m_aLinks.begin() + nPosInList);
		return true;
	}

	bool GetAllLinks(LinksArray &aLinks) {
		for (int i = 0; i < m_aLinks.size(); i++) {
			aLinks.push_back(m_aLinks[i]);
		}

		return true;
	}

	void ShowAll() {
		for (int i = 0; i < m_aLinks.size(); i++) {
			std::cout << "Pos: " << m_aLinks[i]->GetM_nPos();
			std::cout << " Size: " << m_aLinks[i]->GetM_nSize() << std::endl;
		}
	}

	//Добавляє новий лінк типу URL для першого входження підстрічки sSubStr
	bool AddURL(const char *sSubStr, const char *sURL) {
		if (m_refChain.Find(sSubStr) == -1)
			return false;

		CLinkURL *url = new CLinkURL(m_refChain);
		int positionStart = m_refChain.Find(sSubStr);
		std::string charToStr = sSubStr;

		url->AddUrl(sURL);
		url->SetM_nPos(positionStart);
		url->SetM_nSize(size(charToStr));

		m_aLinks.push_back(url);
	}

	//Добавляє новий лінк типу Person для першого входження підстрічки sSubStr
	bool AddPerson(const char *sSubStr, int nGroup, const char *sName) {
		if (m_refChain.Find(sSubStr) == -1)
			return false;

		CLinkPerson *person = new CLinkPerson(m_refChain);
		std::string str = sSubStr;
		int position = m_refChain.Find(sSubStr);
		person->SetGroup(nGroup);
		person->SetName(sName);
		person->SetM_nSize(size(str));
		person->SetM_nPos(position);

		m_aLinks.push_back(person);
	}

private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain &m_refChain;
	LinksArray m_aLinks;
};
