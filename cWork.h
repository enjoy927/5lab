#pragma once
#include <iostream>
#include <fstream>
#include "CLink.h"

class CWorkspace {
public:
	CWorkspace(CDataChain &data);
	//~CWorkspace(void) {}
	//Ініціалізує повну послідовність цифр
	void Init(int nDepth, int nLength);

	//Повертає стрічку із повною послідовністю цифр.
	const char *GetChainString();

	bool Save(std::string &sFilePath);

	bool Load(std::string &sFilePath);

	int Find(const char *sSubStr, int nPos = 0);

	bool AddLink(int nStartPos, int nLength, CLink *pLink);

	bool RemoveLink(int nPosInList);

	bool GetAllLinks(LinksArray &aLinks);

	void ShowAll();

	//Добавляє новий лінк типу URL для першого входження підстрічки sSubStr
	bool AddURL(const char *sSubStr, const char *sURL);

	//Добавляє новий лінк типу Person для першого входження підстрічки sSubStr
	bool AddPerson(const char *sSubStr, int nGroup, const char *sName);

private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain &m_refChain;
	LinksArray m_aLinks;
};
