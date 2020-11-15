#include <fstream>
#include <vector>
#include "cData.cpp"

class CLink {
public:
	CLink(CDataChain &refChain): m_refChain(refChain) {}

	virtual ~CLink(void) {
		delete this;
	}
	
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

	}

	void SetM_nPos(int nPos) {
		m_nPos = nPos;
	}

	void SetM_nSize(int nSize) {
		m_nSize = nSize;
	}
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain &m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize;
};

typedef std::vector<CLink *> LinksArray;