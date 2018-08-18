#include "parallelepiped.h"
#include "rectangle.h"
#include "circle.h"
#include "sphere.h"

int main()
{
    char check;
    do {
		circle cr;
		rectangle rc;
		sphere sp;
		parallelepiped prl;

		cout << "Enter circle data (x1 y1, x2 y2)" << endl;
		cin >> cr;
		cout << endl << "Circle data:" << endl;
		cout << cr;
		
		cout << "Enter rectangle data (x1 y1, x2 y2)" << endl;
		cin >> rc;
		cout << endl << "Rectangle data:" << endl;
		cout << rc;

		cout << "Enter sphere data (x1 y1 z1, x2 y2 z2)" << endl;
		cin >> sp;
		cout << endl << "Sphere data:" << endl;
		cout << sp;

		cout << "Enter parallelepiped data (x1 y1 z1, x2 y2 z2)" << endl;
		cin >> prl;
		cout << endl << "Parallelepiped data:" << endl;
		cout << prl;

        cout << endl << endl << endl; 

        Shape *obj[4];
        obj[0] = &cr;
        obj[1] = &rc;
        obj[2] = &sp;
        obj[3] = new parallelepiped(0,0,0,5,5,5);

        cout << "Shape: ";
        obj[0]->print();
        cout << endl;
        cout << "Area: " << obj[0]->area() << endl;

        cout << "\nShape: ";
        obj[1]->print();
        cout << endl;
        cout << "Area: " << obj[1]->area() << endl;

        cout << "\nShape: ";
        obj[2]->print();
        cout << endl;
        cout << "Area: " << obj[2]->area() << endl;
        cout << "Volume: " << obj[2]->volume() << endl;

        cout << "\nShape: ";
        obj[3]->print();
        cout << endl;
        cout << "Area: " << obj[3]->area() << endl;
        cout << "Volume: " << obj[3]->volume() << endl;

		delete obj[3];

        cout << "\nrepeat? (y/n)" << endl;
        cin >> check;
    } while (check == 'y');
}