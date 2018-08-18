#pragma once

#include "EVM.h"
#include <iomanip>

class port : virtual public EVM
{
protected:
	int RAMVol;
public:
	port();
	port(int ram);
	virtual ~port();
	void SetRAMVol();
	int ShowRAMVol();
	int GetRAMVol();
	friend istream& operator>>(istream& is, port& obj);
	friend ostream& operator<<(ostream& os, const port& obj);
	bool operator== (const port & obj);
	/*bool operator< (const port & obj)
	{
		if (this->RAMVol < obj.RAMVol) return true;
		return false;
	}*/
};