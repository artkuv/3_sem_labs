#include "sphere.h"

void sphere::print()
{
    cout << "Sphere";
}

double sphere::volume()
{
    return 3.14159 * (x2-x1) * (x2-x1) * (x2-x1) / 6;
}

double sphere::area()
{
    return (x2-x1) * (x2-x1) * 3.14159;
}

ostream &operator <<(ostream &stream, sphere &obj)
{
	stream << "Radius: " << (obj.x2 - obj.x1)/2 << endl << endl;

	return stream;
}

istream &operator >>(istream &stream, sphere &obj)
{
	stream >> obj.x1 >> obj.y1 >> obj.z1 >> obj.x2 >> obj.y2 >> obj.z2;

	return stream;
}