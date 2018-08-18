#include "parallelepiped.h"

void parallelepiped::print()
{
    cout << "Parallelepiped";
}

double parallelepiped::volume()
{
    return (x2-x1) * (y2-y1) * (z2-z1);
}

double parallelepiped::area()
{
    return (x2-x1) * 4 + (y2-y1) * 4 + (z2-z1) * 4;
}

ostream &operator <<(ostream &stream, parallelepiped &obj)
{
	stream << "Length: " << obj.x2-obj.x1 << endl << "Width: " << obj.y2-obj.y1 << endl << "Height: " << obj.z2-obj.z1 << endl << endl;

	return stream;
}

istream &operator >>(istream &stream, parallelepiped &obj)
{
	stream >> obj.x1 >> obj.y1 >> obj.z1 >> obj.x2 >> obj.y2 >> obj.z2;

	return stream;
}