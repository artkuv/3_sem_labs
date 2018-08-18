#pragma once
#include "Shape3D.h"

class sphere : public Shape3D
{
protected:
    double x2, y2, z2;
public:
    sphere() : Shape3D()
    {
        x2 = 0;
        y2 = 0;
        z2 = 0;
    }

    ~sphere()
    {
    }

    double volume();
    void print();
    double area();
	friend ostream &operator <<(ostream &stream, sphere obj);
	friend istream &operator >>(istream &stream, sphere &obj);
}; //Сфера
