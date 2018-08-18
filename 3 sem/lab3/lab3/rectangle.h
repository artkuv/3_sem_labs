#pragma once
#include "Shape2D.h"

class rectangle : public Shape2D
{
protected:
    double x2, y2;
public:
    rectangle() : Shape2D()
    {
		x2 = 0;
        y2 = 0;
    }

    ~rectangle()
    {
    }

    double area();
    void print();
	friend ostream &operator <<(ostream &stream, rectangle obj);
	friend istream &operator >>(istream &stream, rectangle &obj);
}; //Прямоугольник
