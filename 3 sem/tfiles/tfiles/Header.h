#pragma once
#include<iostream>
using namespace std;
const int SIZE=5;
class Auto {
private:
	char brand[50];
	int yearOfManuf;
public:
	Auto();
	Auto(char*, int);
	~Auto();
	friend istream &operator >> (istream &, Auto &);
	friend ostream &operator<<(ostream &, Auto);
	//friend void operator >> (istream &, Auto &);
	void writeTXT(const Auto*, char*);
	void readTXT(char*);
	void writeBIN(const Auto*, char*);
	void readBIN(char*);
	void add();
};