#include "graduate.h"

void Graduate::printGrad()
{
	cout << '|' << setw(4) << "Year" << '|' << setw(NAME) << "     Name" << '|' << setw(SNAME) << "       Surname" << '|' << setw(9)
		<< "Grad year" << '|' << setw(SNAME)<< "    Speciality" << '|' << endl;
}

void Graduate::SetGrad(int grad)
{
	this->grad_year = grad;
}

void Graduate::SetSpec(char** spec)
{	
    if (spec == NULL)
		this->speciality = NULL;
    else 
	{
        int i;
        if (this->speciality != NULL)
        {
            for (i = 0; strcmp(this->speciality[i], "") != 0; i++)
                delete[] this->speciality[i];
            delete[] this->speciality[i];
            delete[] this->speciality;
        }
        for (i = 0; strcmp(spec[i], "") != 0; i++);
        this->speciality = new char*[i + 1];
        for (int j = 0; j <= i; j++)
        {
            this->speciality[j] = new char[strlen(spec[j]) + 1];
            strcpy_s(this->speciality[j], strlen(spec[j]) + 1,spec[j]);
        }
    }
}

int Graduate::GetGrad()
{
	return this->grad_year;
}

char** Graduate::GetSpec()
{
	return this->speciality;
}

ostream &operator << (ostream &stream, Graduate &obj)
{
    cout << *dynamic_cast<Learner*>(&obj);

	stream << setw(9) << left << obj.grad_year << '|';
	for (int i = 0; strcmp(obj.speciality[i], ""); i++)
    {
        if (!i)
            stream << setw(SNAME) << left << obj.speciality[i] << '|' << endl;
        else
            stream << '|' << setw(5) << right << '|' << setw(NAME + 1) << '|' << setw(SNAME + 1) << '|'
 			  << setw(10) << '|' << setw(SNAME) << left << obj.speciality[i] << '|' << endl;
    }
    return stream;
}

istream &operator >> (istream &stream, Graduate &obj)
{
	int j;
	char spec[SNAME];
    rewind(stdin);

    cin >> *dynamic_cast<Learner*>(&obj);

    cout << "Enter graduation year: " << endl;
	cin >> j;
	obj.SetGrad(j);

    cout << "Enter speciality (empty string to exit): " << endl;
    char **speciality = new char*[11];
    int i = 0;
    do {
		rewind(stdin);
        cin.getline(spec,SNAME);
        speciality[i] = new char[strlen(spec) + 1];
        strcpy_s(speciality[i], strlen(spec) + 1, spec);
        i++;
    } while (strcmp(speciality[i - 1], "") != 0);

    obj.SetSpec(speciality);

    return stream;
}