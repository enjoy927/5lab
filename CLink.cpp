#include <fstream>
#include <vector>
#include "cData.cpp"

class CLink {
public:
	CLink(CDataChain &refChain): m_refChain(refChain) {
		m_nPos = -1;
		m_nSize = -1;
	}

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

	void GetInform() {
		std::cout << m_nPos << "|" << m_nSize << std::endl;
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