#include <iostream>
#include <string>
#include "cWork.cpp"

int main() {
	CDataSimple ds;
	CWorkspace ws(ds);
	//ds.Generate(15, 20);
	std::string path = "saving.txt";
	ws.Load(path);
	std::cout << ws.GetChainString() << std::endl;
	return 0;
}