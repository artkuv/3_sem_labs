#include "circle.h"

void circle::print()
{
    cout << "Circle";
}

double circle::area()
{
    return 3.14159 * (x2-x1) * (x2-x1) / 4;
}

ostream &operator <<(ostream &stream, circle &obj)
{	
	stream << "Radius: " << (obj.x2 - obj.x1)/2 << endl << endl;

	return stream;
}

istream &operator >>(istream &stream, circle &obj)
{
	stream >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2;

	return stream;
}