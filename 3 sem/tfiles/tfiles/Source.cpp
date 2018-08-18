#include"Header.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
Auto::Auto()
{
	strcpy(brand, " ");
	yearOfManuf = 0;
	//widthBrand = 15;
	//widthYear = 6;
}

Auto::Auto(char *name, int year)
{
	strcpy(brand, name);
	yearOfManuf = year;
	/*widthBrand = 15;
	widthYear = 6;*/
}

Auto::~Auto()
{
	
}

//void operator >> (istream &, Auto &temp)
//{
//
//}

ostream &operator << (ostream &out, Auto obj)
{
	out << setw(15) << left << obj.brand;
	out << setw(6) << left << obj.yearOfManuf;
	return out;
}

istream &operator >> (istream &in, Auto &obj)
{
	in >> obj.brand >> obj.yearOfManuf;
	return in;
}

void Auto::writeTXT(const Auto* obj, char* s)
{
	ofstream out(s);
	if (!out.is_open()) throw "Error";

	for (int i = 0; i<SIZE; i++)
		out << obj[i] << endl;
	out.close();
}

void Auto::readTXT(char* s)
{
	cout << "\nShow:\n";
	ifstream in(s);
	if (!in.is_open()) throw "Error!";
	Auto temp_obj;
	while (!in.eof()) 
	{
		in >> temp_obj;
		if (in.eof()) break;
		cout << temp_obj << endl;
	}
	in.close();
}
void Auto::writeBIN(const Auto* obj, char* s)
{
	ofstream out(s, ios::binary);
	if (!out.is_open()) throw "Error";
	out.write((char*)obj, SIZE * sizeof(Auto));
	out.close();
}

void Auto::readBIN(char* s)
{
	cout << "\nShow:\n";
	ifstream in(s, ios::binary);
	if (!in.is_open()) throw "Error!";

	Auto temp_obj;
	while (!in.eof())
	{
		in.read((char*)&temp_obj, sizeof(Auto));
		if (in.eof()) break;
		cout << temp_obj << endl;
	}
	in.close();
}

void Auto::add()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Input brand and year" << endl;
		cin >> brand;
		cin >> yearOfManuf;
	}
}