#pragma once
#include "Shape.h"

class Shape3D : public Shape
{
protected:
    double x1, y1, z1;
public:
    Shape3D()
    {
        x1 = 0;
        y1 = 0;
        z1 = 0;
    }
    ~Shape3D()
    {
    }
}; //Класс 3D фигур