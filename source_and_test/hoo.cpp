#include<cstdlib>
#include<iostream>
using namespace std;
string cmd;
string hoc,cpp = "test.cpp",exe = "test.exe";
int main(int argc,char* argv[]) {
	if(argc < 2) {
		cout << "ERROR: WHO GOT THE HOOCH?!" << endl;
		return 0;
	} else {
		hoc = argv[1];
		if(argc > 2) cpp = argv[2];
		if(argc > 3) exe = argv[3];
	}
//	cout << "hooch?" << endl;
	cmd = "pcomp ";
	system((cmd + hoc + " " + cpp).c_str());
	cmd = "MinGW64\\bin\\g++ ";
	system((cmd + cpp + " -o " + exe + " -std=c++11 -O2").c_str());
	cmd = "del /s /f /q ";
	system((cmd + cpp + " > nul").c_str());
	return 0;
}
