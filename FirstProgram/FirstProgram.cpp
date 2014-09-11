// FirstProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello Group" << endl;
	string x;
	do{
		cout << "Type bye to exit: ";
		cin >> x;
	} while (x != "bye");
	return 0;
}

