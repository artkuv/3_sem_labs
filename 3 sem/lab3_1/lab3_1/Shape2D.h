#pragma once
#include "Shape.h"

class Shape2D : public Shape
{
protected:
    double x1, y1;
public:
    Shape2D(double a = 0, double b = 0)
    {
        x1 = a;
        y1 = b;
    }

    double volume()
    {
        cout << "No volume in 2D shape" << endl;
        return NULL;
    }

    ~Shape2D()
    {
    }
};