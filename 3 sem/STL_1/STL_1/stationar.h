#pragma once

#include "EVM.h"
#include "port.h"
#include <iomanip>

class Stationar : virtual public EVM
{
protected:
	char* ChipModel;
public:
	Stationar();
	//Stationar(const Stationar & copy);
	Stationar(char* Chip);
	virtual ~Stationar();
	void SetChipModel(char* CPUM);
	char* ShowChipModel();
	char *GetChipModel();
	friend istream& operator>>(istream& is, Stationar& obj);
	friend ostream& operator<<(ostream& os, const Stationar& obj);
	bool operator== (const Stationar & obj);
};