#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class car
{
protected:
	int year;
	string name;
	int number;

public:
	car(int y = 0, string n = "name", int m = 123456)
    {
		this->year = y;
		this->name = n;
		this->number = m;
    }

	~car()
    {
    }

	void print();
	void SetY(int i);
	void SetN(string n);
	void SetM(int m);
	int GetY();
	string GetN();
	int GetM();

	friend ostream &operator << (ostream &stream, car &obj);
	friend istream &operator >> (istream &stream, car &obj);
};