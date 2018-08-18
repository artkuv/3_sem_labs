#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Exeption
{
public:
	int error;
	char *name;

public:
	Exeption(int i, char *Ename)
	{
		this->error = i;
		name = new char[strlen(Ename)+1];
		strcpy_s(this->name,strlen(Ename)+1,Ename);
	}

	virtual ~Exeption()
	{
		delete[] name;
	}

	void error_type()
	{
		cout << endl << this->name << ' - ' << this->error << endl << endl;
	}
};