#include "cWork.cpp"
#include <vector>

//Декларація типу функції, що буде використовуватися для виконання користувацьких команд
typedef void (*ptDlgCommandFunc)(CWorkspace &ws);
class CDlgCommand {
public:
	CDlgCommand(const char *sName, ptDlgCommandFunc pFunc = NULL) {
		m_sName = sName;
		m_pFunc = pFunc;
	}
	//~CDlgCommand(void);

	//Отримання назви команди
	const char *GetName() { return m_sName.c_str(); }
	//Виклик зв"язаної функції
	void Run(CWorkspace &ws) {
		m_pFunc(ws);
	}
private:
	//Назва команди
	std::string m_sName;
	//Вказівник на функцію, що буде використовуватися для виконання користувацьких команд
	ptDlgCommandFunc m_pFunc;
};

class CDialogManager {
public:
	CDialogManager(CWorkspace &ws): m_refWorkspace(ws) {
		m_aCommands.push_back(new CDlgCommand("Quit"));
	}
	//~CDialogManager(void);
	//Реєструє нову команду з ім"ям sName і функцією pFunc
	void RegisterCommand(const char *sName, ptDlgCommandFunc pFunc) {
		m_aCommands.push_back(new CDlgCommand(sName, pFunc));
	}
	//Виконує цикл обробки команд користувача
	void Run() {
		int nCommand = 1;

		while (nCommand) {
			for (size_t i = 0; i < m_aCommands.size(); i++)
				std::cout << i << ". " << m_aCommands[i]->GetName() << std::endl;
			std::cout << "Enter command:";
			std::cin >> nCommand;
			if ((nCommand > 0) && (nCommand < (int)m_aCommands.size()))
				m_aCommands[nCommand]->Run(m_refWorkspace);
			else
				break;

			system("pause");
			system("cls");
		}

	}
private:
	//Вектор вказівників на зареєстровані команди
	std::vector<CDlgCommand *> m_aCommands;
	//Зсилка на робочий простір
	CWorkspace &m_refWorkspace;
};
