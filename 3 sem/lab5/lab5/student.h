#include "learner.h"

class Student : public Learner
{
protected:
	char student_num[10];
	int Curse;

public:
	Student(char *n = "Name", char* sn = "Surname", int y = 0, int cur = 0, char *num = "0000000") : Learner(n,sn,y)
	{
		strcpy_s(this->student_num,NAME,num);
		this->Curse = cur;
	}

	~Student()
	{
	}

	void SetNum(char* num);
	void SetC(int c);
	char* GetNum();
	int GetC();
	void printStud();

	friend ostream &operator << (ostream &stream, Student &obj);
	friend istream &operator >> (istream &stream, Student &obj);
};