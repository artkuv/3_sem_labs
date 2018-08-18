#pragma once
#include "Shape.h"

class Shape3D : public Shape
{
protected:
    double x1, y1, z1;
public:
    Shape3D(double a = 0, double b = 0, double c = 0)
    {
        x1 = a;
        y1 = b;
        z1 = c;
    }

    ~Shape3D()
    {
    }
};