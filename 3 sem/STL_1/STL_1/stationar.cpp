#include "stationar.h"

Stationar::Stationar()
{
	ChipModel = nullptr;
}

//Stationar::Stationar(const Stationar & copy)
//{
//	size = copy.size;
//	model = new char[size + 1];
//	strcpy_s(model, copy.size + 1, copy.model);
//	/*for (int i = 0; i < size; i++)
//	model[i] = copy.model[i];
//	model[size] = 0;*/
//	this->Dday = copy.Dday;
//	this->Mmonth = copy.Mmonth;
//	this->Yyear = copy.Yyear;
//	ChipModel = new char[size + 1];
//	strcpy_s(ChipModel, copy.size + 1, copy.ChipModel);
//}

Stationar::Stationar(char* Chip)
{
	ChipModel = new char[strlen(Chip) + 1];
	strcpy_s(ChipModel, strlen(Chip) + 1, Chip);
}

Stationar::~Stationar()
{
	delete[] ChipModel;
}

void Stationar::SetChipModel(char* Chip)
{
	ChipModel = new char[strlen(Chip) + 1];
	strcpy_s(ChipModel, strlen(Chip) + 1, Chip);
}

char* Stationar::ShowChipModel()
{
	return ChipModel;
}

char *Stationar::GetChipModel()
{
	return this->ChipModel;
}

istream& operator>>(istream& is, Stationar& obj)
{
	char Chip[80];
	cin >> *(dynamic_cast<EVM*>(&obj));
	cout << "¬ведите модель CPU: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Chip, 80);
	obj.SetChipModel(Chip);
	return is;
}

ostream& operator<<(ostream& os,const  Stationar& obj)
{
	return os << obj << setw(17) << obj.ChipModel;
}
//*(dynamic_cast<EVM*>(&obj))

bool Stationar::operator== (const Stationar & obj)
{
	if (ChipModel == obj.ChipModel) return true;
	else return false;
}