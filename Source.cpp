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

void Find(CWorkspace &ws) {
	std::string str;
	int pos;
	std::cout << "Enter the line, you want to find: ";
	std::cin >> str;
	std::cout << "Enter the position: ";
	std::cin >> pos;

	if (ws.Find(str.c_str(), pos) == -1)
		std::cout << "The line not found\n";
	else
		std::cout << "Id from the first occurrence " << ws.Find(str.c_str(), pos) << std::endl;
}


int main() {
	std::cout << "1\n";
	CDataSimple ds;
	CWorkspace ws(ds);
	/*CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Find substring", Find);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);*/

	Load(ws);
	//mgr.Run();
	return 0;
}