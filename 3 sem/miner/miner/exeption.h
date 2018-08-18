#include <vector>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
 
using namespace std;

class exeption
{
protected:
	int error;
	char *name;

public:
	exeption(int i, char *ename)
	{
		this->error = i;
		name = new char[strlen(ename)+1];
		strcpy_s(this->name,strlen(ename)+1,ename);
	}

	virtual ~exeption()
	{
		delete[] name;
	}

	void error_type()
	{
		cout << endl << this->name << ' - ' << this->error << endl << endl;
	}
};