#include <iostream>
#include <fstream>
#include "CLink.cpp"

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

		saveFile << size(save) << std::endl;
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
				for (int j = 0; j < i + 1; j++) {
					AddLink(-1, -1, new CLink(m_refChain));
					m_aLinks[m_aLinks.size() - 1]->Load(loadFile);
					m_aLinks[m_aLinks.size() - 1]->GetInform();
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
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain &m_refChain;
	LinksArray m_aLinks;
};
