#include "port.h"

port::port()
{
	RAMVol = 0;
}

port::port(int ram)
{
	RAMVol = ram;
}

port::~port() {}

void port::SetRAMVol()
{
	cin >> RAMVol;
}

int port::ShowRAMVol()
{
	return RAMVol;
}

int port::GetRAMVol()
{
	return RAMVol;
}

istream& operator>>(istream& is, port& obj)
{
	cin >> *(dynamic_cast<EVM*>(&obj));
	cout << "Введите объём RAM: ";
	obj.SetRAMVol();
	return is;
}

ostream& operator<<(ostream& os, const port& obj)
{
	return os << obj << setw(17) << obj.RAMVol;
}
//*(dynamic_cast<EVM*>(&obj))

bool port::operator== (const port & obj)
{
	if (RAMVol == obj.RAMVol) return true;
	else return false;
}