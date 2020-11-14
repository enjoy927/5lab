#include <iostream>
#include <fstream>
#include "cData.cpp"

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

		std::ofstream saveFile(sFilePath, std::fstream::app);
		saveFile << GetChainString() << std::endl;
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
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain &m_refChain;
};
