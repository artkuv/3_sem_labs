#include "EVM.h"

EVM::EVM()
{
	model = nullptr;
	Dday = 0;
	Mmonth = 0;
	Yyear = 0;
}

EVM::EVM(const EVM & copy)
{
	cout << "Copy constructor" << endl;
	size = copy.size;
	model = new char[size + 1];
	strcpy_s(model, copy.size + 1, copy.model);
	/*for (int i = 0; i < size; i++)
	model[i] = copy.model[i];
	model[size] = 0;*/
	this->Dday = copy.Dday;
	this->Mmonth = copy.Mmonth;
	this->Yyear = copy.Yyear;
}

EVM::EVM(char *str1, int day, int month, int year)
{
	model = new char[strlen(str1) + 1];
	strcpy_s(model, strlen(str1) + 1, str1);
	Dday = day;
	Mmonth = month;
	Yyear = year;
}

EVM::~EVM()
{
	//	delete[] model;
}

void EVM::showDate()
{
	cout << "" << Dday << ". " << Mmonth << ". " << Yyear;
}

void EVM::setDate()
{
	cin >> Dday;
	cin >> Mmonth;
	cin >> Yyear;
}

void EVM::setModel(char *st)
{
	size = strlen(st);
	model = new char[strlen(st) + 1];
	strcpy_s(model, strlen(st) + 1, st);
}

char* EVM::showModel()
{
	return model;
}

char *EVM::GetModel()
{
	return this->model;
}

int EVM::GetDday()
{
	return Dday;
}

int EVM::GetMmonth()
{
	return Mmonth;
}

int EVM::GetYyear()
{
	return Yyear;
}

istream& operator>>(istream& is, EVM& obj)
{
	char nam[80];
	system("cls");
	cout << "Введите имя и модель: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(nam, 80);
	obj.setModel(nam);
	cout << "Введите дату [ДД/ММ/ГГ]: ";
	obj.setDate();
	return is;
}

ostream& operator<<(ostream& os, const EVM& obj)
{
	return os << setw(17) << obj.model << setw(9) << obj.Dday << "." << obj.Mmonth << "." << obj.Yyear;
}

bool EVM::operator== (const EVM & obj)
{
	if (model == obj.model) return true;
	else return false;
}

//virtual bool EVM::operator < (const EVM & obj)
//{
//	if (this->GetYyear() < obj.GetYyear()) return true;
//	return false;
//}