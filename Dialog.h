#pragma once
#include "cWork.h"
#include <vector>

//Декларація типу функції, що буде використовуватися для виконання користувацьких команд
typedef void (*ptDlgCommandFunc)(CWorkspace &ws);
class CDlgCommand {
public:
	CDlgCommand(const char *sName, ptDlgCommandFunc pFunc = NULL);
	//~CDlgCommand(void);

	//Отримання назви команди
	const char *GetName();
	//Виклик зв"язаної функції
	void Run(CWorkspace &ws);
private:
	//Назва команди
	std::string m_sName;
	//Вказівник на функцію, що буде використовуватися для виконання користувацьких команд
	ptDlgCommandFunc m_pFunc;
};

class CDialogManager {
public:
	CDialogManager(CWorkspace &ws);
	//~CDialogManager(void);
	//Реєструє нову команду з ім"ям sName і функцією pFunc
	void RegisterCommand(const char *sName, ptDlgCommandFunc pFunc);
	//Виконує цикл обробки команд користувача
	void Run();
private:
	//Вектор вказівників на зареєстровані команди
	std::vector<CDlgCommand *> m_aCommands;
	//Зсилка на робочий простір
	CWorkspace &m_refWorkspace;
};
