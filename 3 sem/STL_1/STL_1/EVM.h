#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int ChMin = 1;
const int ChMax = 10;

class EVM
{
protected:
	char *model;
	int Dday, Mmonth, Yyear;
	int size;
public:
	EVM();
	EVM(const EVM & copy);
	EVM(char *str1, int day, int month, int year);
	virtual ~EVM();
	void showDate();
	void setDate();
	void setModel(char *st);
	char *showModel();
	char *GetModel();
	int GetDday();
	int GetMmonth();
	int GetYyear();
	friend istream& operator>> (istream & is, EVM& obj);
	friend ostream& operator<<(ostream& os,const EVM& obj);
	bool operator== (const EVM & obj);
	bool operator < (const EVM & obj) const
	{
		if (this->Yyear < obj.Yyear) return true;
		return false;
	};
};
