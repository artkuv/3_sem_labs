#pragma once
#include "Shape3D.h"

class parallelepiped : public Shape3D
{
protected:
    double x2, y2, z2;
public:
    parallelepiped() : Shape3D()
    {
		x2 = 0;
        y2 = 0;
        z2 = 0;
    }

    ~parallelepiped()
    {
    }

    double volume();
    void print();
    double area();
	friend ostream &operator <<(ostream &stream, parallelepiped obj);
	friend istream &operator >>(istream &stream, parallelepiped &obj);
}; //Параллелепипед
