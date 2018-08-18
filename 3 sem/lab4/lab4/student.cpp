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
	int i;
	char num[10];
	rewind(stdin);

	cin >> *dynamic_cast<Learner*>(&obj);

	cout << "Enter student number: " << endl;
	cin >> num;
	obj.SetNum(num);

	cout << "Enter Curse: " << endl;
	cin >> i;
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