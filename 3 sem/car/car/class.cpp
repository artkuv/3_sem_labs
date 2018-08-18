#include "class.h"

void car::print()
{
	cout << setw(6) << left << "Year" << setw(8) << left << "Number" << setw(30) << left << "Name" << endl;
}

void car::SetY(int i)
{
	this->year = i;
}

void car::SetN(string n)
{
	this->name = n;
}

void car::SetM(int m)
{
	this->number = m;
}

int car::GetY()
{
	return this->year;
}

string car::GetN()
{
	return this->name;
}

int car::GetM()
{
	return this->number;
}

istream &operator >> (istream &stream, car &obj)
{
	int i;
	string n;
	int m;
	rewind(stdin);

	cout << "Enter year: " << endl;
	stream >> i;
	obj.SetY(i);
	
	cout << "Enter number: " << endl;
	stream >> m;
	obj.SetM(m);
	
	rewind(stdin);
	cout << "Enter name: " << endl;
	getline(stream, n);
	obj.SetN(n);

	return stream;
}

ostream &operator << (ostream &stream, car &obj)
{
	stream << setw(6) << left << obj.year;
	stream << setw(8) << left << obj.number;
	stream << setw(30) << left << obj.name << endl;
	//stream << obj.year << " " << obj.name << " " << obj.number;
	return stream;
}