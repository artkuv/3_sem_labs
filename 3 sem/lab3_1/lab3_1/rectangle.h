#pragma once
#include "Shape2D.h"

class rectangle : public Shape2D
{
protected:
    double x2, y2;
public:
    rectangle(double a = 0, double b = 0, double a1 = 0, double b1 = 0) : Shape2D(a,b)
    {
		x2 = a1;
        y2 = b1;
    }

    ~rectangle()
    {
    }

    double area();
    void print();
	friend ostream &operator <<(ostream &stream, rectangle &obj);
	friend istream &operator >>(istream &stream, rectangle &obj);
}; 
