#pragma once
#include <iostream>
using namespace std;

class Shape
{
public:
    Shape()
    {
    }

	~Shape()
    {
    }

    virtual void print() = 0;
    virtual double area() = 0;
    virtual double volume() = 0;
};