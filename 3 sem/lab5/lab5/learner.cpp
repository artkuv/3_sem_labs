#pragma once
#include "learner.h"

void Learner::SetY(int i)
{
	this->year = i;
}

void Learner::SetN(char *n)
{
	strcpy_s(this->name,NAME,n);
}

void Learner::SetS(char *sn)
{
	strcpy_s(this->surname,SNAME,sn);
}

int Learner::GetY()
{
	return this->year;
}

char* Learner::GetN()
{
	return this->name;
}

char* Learner::GetS()
{
	return this->surname;
}

istream &operator >> (istream &stream, Learner &obj)
{
	int i,flag=0;
	char *err;
	err="invalid values";
	char  name[NAME], surname[SNAME];
	rewind(stdin);

	do
	{
		try
		{
			cout << endl << "Enter birth year: " << endl;
			cin >> i;
			if(i<1900 || i>2015)
			{
				flag=1;
				throw Input(1,err);
			}
			else 
				flag=0;
		}
		catch(Input &EX)
		{
			cout << "Error #" << EX.error << " - " << EX.name;
		}
	}
	while(flag==1);
	obj.year=i;

	cout << "Enter name: " << endl;
	rewind(stdin);
	cin.getline(name,NAME);
	strcpy(obj.name,name);
	
	cout << "Enter surname: " << endl;
	cin >> surname;
	strcpy(obj.surname,surname);

	return stream;
}

ostream &operator << (ostream &stream, Learner &obj)
{
	stream << '|' << setw(4) << left << obj.year << '|';
	stream << setw(NAME) << left << obj.name << '|';
	stream << setw(SNAME) << left << obj.surname << '|';
	return stream;
}