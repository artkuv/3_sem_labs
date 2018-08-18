#pragma once
#include "Shape3D.h"

class sphere : public Shape3D
{
protected:
    double x2, y2, z2;
public:
    sphere(double a = 0, double b = 0, double c = 0, double a1 = 0, double b1 = 0, double c1 = 0) : Shape3D(a,b,c)
    {
        x2 = a1;
        y2 = b1;
        z2 = c1;
    }

    ~sphere()
    {
    }

    double volume();
    void print();
    double area();
	friend ostream &operator <<(ostream &stream, sphere &obj);
	friend istream &operator >>(istream &stream, sphere &obj);
}; 
