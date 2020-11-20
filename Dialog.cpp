#include <vector>
#include "Dialog.h"

//Декларація типу функції, що буде використовуватися для виконання користувацьких команд
typedef void (*ptDlgCommandFunc)(CWorkspace &ws);
CDlgCommand::CDlgCommand(const char *sName, ptDlgCommandFunc pFunc) {
	m_sName = sName;
	m_pFunc = pFunc;
}
	//~CDlgCommand(void);

	//Отримання назви команди
const char *CDlgCommand::GetName() { return m_sName.c_str(); }
//Виклик зв"язаної функції
void CDlgCommand::Run(CWorkspace &ws) {
	m_pFunc(ws);
}

CDialogManager::CDialogManager(CWorkspace &ws): m_refWorkspace(ws) {
	m_aCommands.push_back(new CDlgCommand("Quit"));
}
	//~CDialogManager(void);
	//Реєструє нову команду з ім"ям sName і функцією pFunc
void CDialogManager::RegisterCommand(const char *sName, ptDlgCommandFunc pFunc) {
	m_aCommands.push_back(new CDlgCommand(sName, pFunc));
}
	//Виконує цикл обробки команд користувача
void CDialogManager::Run() {
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