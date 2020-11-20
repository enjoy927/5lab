#pragma once
#include <iostream>
#include <fstream>
class CDataChain {
public:
	//CDataChain(void);
	virtual ~CDataChain(void);
	//віртуальна функція, що має генерувати повну послідовність цифр.
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	//повертає довжину згенерованої послідовності цифр.
	virtual size_t GetLength(const char *sSubStr) = 0;
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
	void Generate(int nDepth, int nMaxLength = 0);
	const char *GetFullString();
	size_t GetLength(const char *sSubStr);
	void SetM_sChain(std::string str);

	int Find(const char *sSubStr, int nPos = 0);
};

class CDataPi: public CDataChain {
public:
	/*CDataPi(void) {}
	~CDataPi(void) {}*/

	void Generate(int nDepth, int nLength = 0);

	size_t GetLength(const char *sSubStr);
	//повертає позицію входження підстрічки sSubStr починаючи із nPos.
	// -1, якщо підстрічки не знайдено
	int Find(const char *sSubStr, int nPos = 0);
	//повертає підстрічку починаючи із nPos довжиною nLength. або до кінця послідовності
	//std::string GetSubStr(int nPos, int nLength = -1);
	//повертає всю згенеровану послідовність цифр
	const char *GetFullString();
	void SetM_sChain(std::string str);
	std::string GetString();
};