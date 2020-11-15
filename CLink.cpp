#include <fstream>
#include <vector>
#include "cData.cpp"

typedef std::vector<CLink *> LinksArray;
class CLink {
public:
	CLink(CDataChain &refChain): m_refChain(refChain) {}
	//virtual ~CLink(void);
	
	//Пробує прив"язати об"єкт до підстрічки у послідовності
	//bool Attach(const char *sSubStr);
	
	//Форматований вивід на консоль
	//virtual void Output(std::ostream &os);

	//Зберігає об"єкт у вихідному потоці
	virtual bool Save(std::ostream &so) {
		so << m_nPos << " " << m_nSize << std::endl;
	}

	//Зчитує об"єкт із вхідного потоку
	//virtual bool Load(std::istream &is);
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain &m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize;
};
