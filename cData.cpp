#include <iostream>
#include <string>

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
	//int Find(const char *sSubStr, int nPos = 0);
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
		m_sChain += generateStr + "\n";
	}

	const char *GetFullString() override {
		return m_sChain.c_str();
	}

	void SetM_sChain(std::string str) override {
		m_sChain = str;
	}
};