#pragma once
#include "Shape2D.h"

class circle : public Shape2D
{
protected:
    double x2, y2;
public:
    circle(double a = 0, double b = 0, double a1 = 0, double b1 = 0) : Shape2D(a,b)
    {
		x2 = a1;
        y2 = b1;
    }

    ~circle()
    {
    }

    double area();
    void print();
	friend ostream &operator <<(ostream &stream, circle &obj);
	friend istream &operator >>(istream &stream, circle &obj);
}; 
