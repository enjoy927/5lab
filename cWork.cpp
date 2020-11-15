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

		saveFile << m_aLinks.size();
		for (int i = 0; i < m_aLinks.size(); i++) {
			*m_aLinks[i]->Save(saveFile);
		}
		
		saveFile.close();

		return true;
	}

	bool Load(std::string &sFilePath) {
		std::ifstream loadFile(sFilePath);
		
		if (!loadFile.is_open())
			return false;
		
		std::string str, resultStr;
		while (std::getline(loadFile, str)) {
			resultStr += str + '\n';
		}
		m_refChain.SetM_sChain(resultStr);

		loadFile.close();

		return true;
	}

	int Find(const char *sSubStr, int nPos = 0) {
		return m_refChain.Find(sSubStr, nPos);
	}

	//bool AddLink(int nStartPos, int nLength, CLink* pLink) {

	//}
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain &m_refChain;
	LinksArray m_aLinks;
};
