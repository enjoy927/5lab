#include <iostream>
#include <string>
#include "Dialog.cpp"

void Save(CWorkspace &ws) {
	std::cout << "save func";
}

int main() {
	CDataSimple ds;
	CWorkspace ws(ds);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Save", Save);
	mgr.Run();
	return 0;
}