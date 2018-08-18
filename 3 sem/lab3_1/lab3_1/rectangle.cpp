#include "rectangle.h"

void rectangle::print()
{
    cout << "Rectangle";
}

double rectangle::area()
{ 
    return (x2-x1) * (y2-y1);
}

ostream &operator <<(ostream &stream, rectangle &obj)
{
	stream << "Length: " << obj.x2-obj.x1 << endl << "Width: " << obj.y2-obj.y1 << endl << endl;

	return stream;
}

istream &operator >>(istream &stream, rectangle &obj)
{
	stream >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2;

	return stream;
}