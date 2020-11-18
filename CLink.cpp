#include <fstream>
#include <vector>
#include <string>
#include "cData.h"
#include "cLink.h"

class CLink {
public:
	CLink(CDataChain &refChain): m_refChain(refChain) {}

	virtual ~CLink(void) {}
	
	//Пробує прив"язати об"єкт до підстрічки у послідовності
	//bool Attach(const char *sSubStr);
	
	//Форматований вивід на консоль
	//virtual void Output(std::ostream &os);

	//Зберігає об"єкт у вихідному потоці
	virtual bool Save(std::ostream &so) {
		so << m_nPos << " " << m_nSize << std::endl;
		return true;
	}

	//Зчитує об"єкт із вхідного потоку
	virtual bool Load(std::istream &is) {
		std::string str;
		std::getline(is, str);
		if (str == "")
			std::cout << "Error load";
		else {
			std::string strNum;
			int j = 0;
			while (str[j] != ' ') {
				strNum += str[j];
				j++;
			}
			m_nPos = std::stoi(strNum);
			strNum = "";
			for (++j; j < size(str); j++) {
				strNum += str[j];
			}
			m_nSize = std::stoi(strNum);
			return true;
		}

		return false;
	}

	void SetM_nPos(int nPos) {
		m_nPos = nPos;
	}

	void SetM_nSize(int nSize) {
		m_nSize = nSize;
	}

	int GetM_nPos() {
		return m_nPos;
	}

	int GetM_nSize() {
		return m_nSize;
	}
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain &m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos = -1;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize = -1;
};
typedef std::vector<CLink *> LinksArray;

class CLinkURL: public CLink {
public:
	CLinkURL(CDataChain &refChain): CLink(refChain) {}

	virtual ~CLinkURL(void) {}

	void AddUrl(const char *sSubStr) {
		m_sURL = sSubStr;
	}

private:
	std::string m_sURL;
};

class CLinkPerson: public CLink {
public:
	CLinkPerson(CDataChain &refChain): CLink(refChain) {}
	virtual ~CLinkPerson(void) {}

	void SetGroup(int group) {
		m_nGroupCode = group;
	}

	void SetName(std::string name) {
		m_sName = name;
	}

private:
	int m_nGroupCode;
	std::string m_sName;
};