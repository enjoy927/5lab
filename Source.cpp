#include <iostream>
#include <string>
#include "Dialog.cpp"

void Save(CWorkspace &ws) {
	std::string path;
	std::cout << "Enter the path to the file(without extension):";
	std::cin >> path;
	path += ".txt";
	if (ws.Save(path))
		std::cout << "Successfuly\n";
	else
		std::cout << "Error\n";
}

void Load(CWorkspace &ws) {
	std::string path;
	std::cout << "Enter the path to the file(without extension):";
	std::cin >> path;
	path += ".txt";
	if (ws.Load(path))
		std::cout << "Successfuly.\n";
	else {
		std::cout << "Error. ";
		std::cout << "No such file\n";
	}
}

void Init(CWorkspace &ws) {
	int nDepth = 0, nLength = 0;
	std::cout << "Depth: ";
	std::cin >> nDepth;

	std::cout << "Length: ";
	std::cin >> nLength;
	
	ws.Init(nDepth, nLength);
}

void ShowFullSequence(CWorkspace &ws) {
	std::cout << ws.GetChainString() << std::endl;
}


int main() {
	CDataSimple ds;
	CWorkspace ws(ds);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);

	mgr.Run();
	return 0;
}