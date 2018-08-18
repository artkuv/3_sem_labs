#include "student.h"

void Student::printStud()
{
	cout << '|' << setw(4) << left << "Year" << '|' << setw(NAME) << left << "     Name" << '|' << setw(SNAME) << left << "       Surname" << '|' << setw(6)
		 << left << "Curse" << '|' << setw(10) << left << "Student num" << '|' << endl;
}

void Student::SetNum(char* num)
{
	strcpy_s(this->student_num,NAME,num);
}

void Student::SetC(int c)
{
	this->Curse = c;
}

char* Student::GetNum()
{
	return this->student_num;
}

int Student::GetC()
{
	return this->Curse;
}

istream &operator >> (istream &stream, Student &obj)
{
	int i,flag=0;
	char num[10];
	char *err;
	err="invalid values";
	rewind(stdin);

	cin >> *dynamic_cast<Learner*>(&obj);

	cout << "Enter student number: " << endl;
	cin >> num;
	obj.SetNum(num);

	do
	{
		try
		{
			cout << endl << "Enter curse: " << endl;
			cin >> i;
			if(i<0 || i>5)
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
	obj.SetC(i);

	return stream;
}

ostream &operator << (ostream &stream, Student &obj)
{
	cout << *dynamic_cast<Learner*>(&obj);

	stream << setw(6) << left << obj.Curse << '|';
	stream << setw(11) << left << obj.student_num << '|';

	return stream;
}