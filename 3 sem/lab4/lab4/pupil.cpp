#include "pupil.h"

void Pupil::printPup()
{
	cout << '|' << setw(4) << left << "Year" << '|' << setw(NAME) << left << "     Name" << '|' << setw(SNAME) << left << "       Surname" << '|' << setw(6) 
		 << left << "Class" << '|' << setw(7) << left << "Sr Ball" << '|' << endl;
}

void Pupil::SetCl(int cl)
{
	this->studing_class = cl;
}

void Pupil::SetSr(double sr)
{
	this->sr_mark = sr;
}

double Pupil::GetSr()
{
	return this->sr_mark;
}

int Pupil::GetCl()
{
	return this->studing_class;
}

istream &operator >> (istream &stream, Pupil &obj)
{
	int i;
	double m;
	rewind(stdin);

	cin >> *dynamic_cast<Learner*>(&obj);

	cout << "Enter studing class: " << endl;
	cin >> i;
	obj.SetCl(i);

	cout << "sr_mark: " << endl;
	cin >> m;
	obj.SetSr(m);

	return stream;
}

ostream &operator << (ostream &stream, Pupil &obj)
{
	cout << *dynamic_cast<Learner*>(&obj);

	stream << setw(6) << left << obj.studing_class << '|';
	stream << setw(7) << left << obj.sr_mark << '|';

	return stream;
}