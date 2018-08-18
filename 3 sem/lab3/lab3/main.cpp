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

		cin >> cr;
		cout << cr;
		
		cin >> rc;										
		cout << rc;

		cin >> sp;
		cout << sp;

		cin >> prl;
		cout << prl;

        cout << endl << endl << endl;

        cout << "Shape: ";
        cr.print();
        cout << "Area: " << cr.area() << endl;

        cout << "\nShape: ";
        rc.print();
        cout << "Area: " << rc.area() << endl;

        cout << "\nShape: ";
        sp.print();
        cout << "Area: " << sp.area() << endl;
        cout << "Volume: " << sp.volume() << endl;

        cout << "\nShape: ";
        prl.print();
        cout << "Area: " << prl.area() << endl;
        cout << "Volume: " << prl.volume() << endl;

        cout << "\nrepeat? (y/n)" << endl;
        cin >> check;
    } while (check == 'y');
}