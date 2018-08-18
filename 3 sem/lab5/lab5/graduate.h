#include "learner.h"

class Graduate : public Learner
{
protected:
	char** speciality;
	int grad_year;

public:
	Graduate(char *n = "Name", char* sn = "Surname", int y = 0, int grad = 0, char** spec = NULL) : Learner(n,sn,y)
	{
		this->grad_year = grad;
		SetSpec(spec);
	}

	~Graduate()
	{
		if (this->speciality != NULL) 
		{
            int i;
            for (i = 0; strcmp(this->speciality[i], "") != 0; i++)
                delete[] this->speciality[i];
            delete[] this->speciality[i];
            delete[] this->speciality;
        }
	}

	void SetGrad(int grad);
	void SetSpec(char** spec);
	int GetGrad();
	char** GetSpec();
	void printGrad();

	friend ostream &operator << (ostream &stream, Graduate &obj);
    friend istream &operator >> (istream &stream, Graduate &obj);
};