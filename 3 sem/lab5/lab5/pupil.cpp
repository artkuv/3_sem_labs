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
	int a,i,flag=0;
	double m;
	char *err;
	err="invalid values";
	rewind(stdin);

	cin >> *dynamic_cast<Learner*>(&obj);

	do
	{
		try
		{
			cout << endl << "Enter studing class: " << endl;
			cin >> i;
			if(i<0 || i>11)
			{
				flag=1;
				throw Input(1,err);
			}
			else 
				flag=0;
		}
		catch(Input &EX)
		{
			cout << "Error #" << EX.error << " - " << EX.name;
		}
	}
	while(flag==1);
	obj.SetCl(i);

do
	{
		try
		{
			cout << endl << "Enter sr_mark: " << endl;
			cin >> m;
			if(m<0 || m>10)
			{
				flag=1;
				throw Input(1,err);
			}
			else 
				flag=0;
		}
		catch(Input &EX)
		{
			cout << "Error #" << EX.error << " - " << EX.name;
		}
	}
	while(flag==1);	
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