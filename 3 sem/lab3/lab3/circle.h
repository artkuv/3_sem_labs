#pragma once
#include "Shape2D.h"

class circle : public Shape2D
{
protected:
    double x2, y2;
public:
    circle() : Shape2D()
    {
		x2 = 0;
        y2 = 0;
    }

    ~circle()
    {
    }

    double area();
    void print();
	friend ostream &operator <<(ostream &stream, circle obj);
	friend istream &operator >>(istream &stream, circle &obj);

}; // Круг
