#include "parallelepiped.h"
#include "rectangle.h"
#include "circle.h"
#include "sphere.h"

 void circle::print()
{
    cout << "Circle" << endl;
}

void rectangle::print()
{
    cout << "Rectangle" << endl;
}

void sphere::print()
{
    cout << "Sphere" << endl;
}

void parallelepiped::print()
{
    cout << "Parallelepiped" << endl;
}

double circle::area()
{
    return 3.14159 * (x2-x1) * (x2-x1);
}

double rectangle::area()
{ 
    return (x2-x1) * (y2-y1);
}

double sphere::volume()
{
    return 3.14159 * (x2-x1) * (x2-x1) * (x2-x1) / 6;
}

double parallelepiped::volume()
{
    return (x2-x1) * (y2-y1) * (z2-z1);
}

double parallelepiped::area()
{
    return (x2-x1) * 4 + (y2-y1) * 4 + (z2-z1) * 4;
}

double sphere::area()
{
    return (x2-x1) * (x2-x1) * 3.14159;
}

ostream &operator <<(ostream &stream, circle obj)
{	
	stream << "Circle data:" << endl;
	stream << "Radius: " << (obj.x2 - obj.x1)/2 << endl;

	return stream;
}

ostream &operator <<(ostream &stream, rectangle obj)
{
	stream << "Rectangle data:" << endl;
	stream << "Length: " << obj.x2-obj.x1 << endl << "Width: " << obj.y2-obj.y1 << endl;

	return stream;
}

ostream &operator <<(ostream &stream, parallelepiped obj)
{
	stream << "Parallelepiped data:" << endl;
	stream << "Length: " << obj.x2-obj.x1 << endl << "Width: " << obj.y2-obj.y1 << endl << "Height: " << obj.z2-obj.z1 << endl;

	return stream;
}

ostream &operator <<(ostream &stream, sphere obj)
{
	stream << "Sphere data:" << endl;
	stream << "Radius: " << (obj.x2 - obj.x1)/2 << endl;

	return stream;
}

istream &operator >>(istream &stream, circle &obj)
{
	cout << "Enter circle data (x1 y1, x2 y2)" << endl;
	stream >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2;

	return stream;
}

istream &operator >>(istream &stream, rectangle &obj)
{
	cout << "Enter rectangle data (x1 y1, x2 y2)" << endl;
	stream >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2;

	return stream;
}

istream &operator >>(istream &stream, sphere &obj)
{
	cout << "Enter sphere data (x1 y1 z1, x2 y2 z2)" << endl;
	stream >> obj.x1 >> obj.y1 >> obj.z1 >> obj.x2 >> obj.y2 >> obj.z2;

	return stream;
}

istream &operator >>(istream &stream, parallelepiped &obj)
{
	cout << "Enter parallelepiped data (x1 y1 z1, x2 y2 z2)" << endl;
	stream >> obj.x1 >> obj.y1 >> obj.z1 >> obj.x2 >> obj.y2 >> obj.z2;

	return stream;
}