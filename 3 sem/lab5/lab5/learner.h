#pragma once
#include "input.h"

#define NAME 15
#define SNAME 20

class Learner
{
protected:
	int year;
	char name[NAME];
	char surname[SNAME];

public:
	Learner(char *n = "Name", char* sn = "Surname", int y = 0)
    {
		this->year = y;
		strcpy_s(this->name, NAME, n);
		strcpy_s(this->surname, SNAME, sn);
    }

	virtual ~Learner()
    {
    }

	virtual void SetY(int i);
	virtual void SetN(char *n);
	virtual void SetS(char *sn);
	virtual int GetY();
	virtual char* GetN();
	virtual char* GetS();

	friend ostream &operator << (ostream &stream, Learner &obj);
	friend istream &operator >> (istream &stream, Learner &obj);
};