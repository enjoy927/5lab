#pragma once
#include <fstream>
#include <vector>
#include "cData.h"

class CLink {
public:
	CLink(CDataChain &refChain): m_refChain(refChain) {}

	virtual ~CLink(void) {}

	//Пробує прив"язати об"єкт до підстрічки у послідовності
	//bool Attach(const char *sSubStr);

	//Форматований вивід на консоль
	//virtual void Output(std::ostream &os);

	//Зберігає об"єкт у вихідному потоці
	virtual bool Save(std::ostream &so);

	//Зчитує об"єкт із вхідного потоку
	virtual bool Load(std::istream &is);

	void SetM_nPos(int nPos);

	void SetM_nSize(int nSize);

	int GetM_nPos();

	int GetM_nSize();
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain &m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize;
};
typedef std::vector<CLink *> LinksArray;

class CLinkURL: public CLink {
public:
	CLinkURL(CDataChain &refChain);

	virtual ~CLinkURL(void);

	void AddUrl(const char *sSubStr);

private:
	std::string m_sURL;
};

class CLinkPerson: public CLink {
public:
	CLinkPerson(CDataChain *refChain);
	virtual ~CLinkPerson(void);

	void SetGroup(int group);

	void SetName(std::string name);

private:
	int m_nGroupCode;
	std::string m_sName;
};