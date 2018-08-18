#include "learner.h"

class Pupil : public Learner
{
protected:
	int studing_class;
	double sr_mark;

public:
	Pupil(char *n = "Name", char* sn = "Surname", int y = 0,int cl = 0, double sr = 0) : Learner(n,sn,y)
	{
		this->studing_class = cl;
		this->sr_mark = sr;
    }

	~Pupil()
	{
    }

	void SetCl(int cl);
	void SetSr(double sr);
	int GetCl();
	double GetSr();
	void printPup();

	friend ostream &operator << (ostream &stream, Pupil &obj);
	friend istream &operator >> (istream &stream, Pupil &obj);
};