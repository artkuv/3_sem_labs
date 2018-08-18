#pragma once
#include "Shape.h"

class Shape2D : public Shape
{
protected:
    double x1, y1;
public:
    Shape2D()
    {
        x1 = 0;
        y1 = 0;
    }
    double volume()
    {
        cout << "No volume in 2D shape" << endl;
        return NULL;
    }
    ~Shape2D()
    {
    }
}; //Класс 2D фигур