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
	int i;
	char  name[NAME], surname[SNAME];
	rewind(stdin);

	cout << "Enter birth year: " << endl;
	cin >> i;
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