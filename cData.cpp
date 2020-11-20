#include <iostream>
#include <string>
#include <iomanip>
#include "cData.h"

class CDataChain {
public:
	//CDataChain(void);
	//virtual ~CDataChain(void);
	//віртуальна функція, що має генерувати повну послідовність цифр.
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	//повертає довжину згенерованої послідовності цифр.
	//size_t GetLength();
	//повертає позицію входження підстрічки sSubStr починаючи із nPos.
	// -1, якщо підстрічки не знайдено
	virtual int Find(const char *sSubStr, int nPos = 0) = 0;
	//повертає підстрічку починаючи із nPos довжиною nLength. або до кінця послідовності
	//std::string GetSubStr(int nPos, int nLength = -1);
	//повертає всю згенеровану послідовність цифр
	virtual const char *GetFullString() = 0;
	virtual void SetM_sChain(std::string str) = 0;
protected:
	//стрічка із згенерованою послідовністю цифр
	std::string m_sChain;
};

class CDataSimple: public CDataChain {
public:
	//CDataSimple(void) {}
	//~CDataSimple(void) override {}
	//Реалізація генератора повної послідовності цифр
	void Generate(int nDepth, int nMaxLength = 0) override {
		int i = 0;
		std::string generateStr = "";
		while (size(generateStr) < nMaxLength) {
			if (i > nDepth)
				break;

			generateStr += std::to_string(i);
			i++;
		}
		m_sChain = generateStr + "\n";
	}

	const char *GetFullString() override {
		return m_sChain.c_str();
	}

	void SetM_sChain(std::string str) override {
		m_sChain = str;
	}

	int Find(const char *sSubStr, int nPos = 0) {
		bool f = false;
		std::string sSubStr1 = sSubStr;
		int resultId = -1;
		for (int i = nPos; i < size(m_sChain); i++) {
			if (m_sChain[i] == sSubStr1[0]) {
				if (size(sSubStr1) <= size(m_sChain) - i) {
					int count = 0;
					int id = i;
					resultId = i;

					for (int j = 0; j < size(sSubStr1); j++) {
						if (m_sChain[id] == sSubStr1[j]) {
							count++;
							id++;
						}
					}

					if (count == size(sSubStr1)) {
						f = true;
						break;
					}
				}
			}
		}

		if (f)
			return resultId;
		else
			return -1;
	}
};

class CDataPi: public CDataChain {
	//CDataPi(void) {}
	~CDataPi(void) {}

	void Generate(int nDepth, int nLength = 0) override {
		double Pi = 4 * atan(1);

		std::ofstream file("data.txt");
		file << std::setprecision(nLength) << Pi;
		file.close();

		std::string str = "";
		std::ifstream inputFile("data.txt");
		inputFile >> str;
		inputFile.close();

		for (int i = 0; i < size(str); i++) {
			if (str[i] == '.')
				continue;

			m_sChain += str[i];
		}
	}
};