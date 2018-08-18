#include "class.h"

int main()
{
	char check;
	
	do 
	{
		int size1, size2, size;
		int i=0,j,z;
		const char *txt = "Artem Kulchitsky";
		char ss[80];

		cout << "Enter text 1: ";
		cin >> ss;
		String txt1(ss);											

		cout << "text 1: ";
		size1 = txt1.GetString();		

		rewind(stdin);

		cout << endl << endl<< "Enter text 2: ";
		cin >> ss;
		String txt2(ss);

		cout << "text 2: " ;
		size2 = txt2.GetString();	
		
		cout << endl;
		txt1 == txt2;

		cout << endl <<  "txt1++"  << endl;
		txt1++;														
		txt1.GetString();

		cout << endl << endl << "txt1--" << endl;
		--txt1;														
		txt1.GetString();

		cout << endl << endl << "txt1+="  << endl << "enter x:" << endl;
		cin >> i;
		if((txt1+=i)==1)
		{
			system("pause");
			return 0;	
		}
		txt1.GetString();
		String txt3(size1 + size2);

		cout << endl << endl << "txt1 + txt2" << endl;
		txt3 = txt1 + txt2;														
		size = txt3.GetString();

		cout << endl << endl << "txt + txt2" << endl;
		txt3 = txt + txt2;													
		size = txt3.GetString();

		cout << endl << endl << "txt1 + txt" << endl;
		txt3 = txt1 + txt;													
		size = txt3.GetString();

		cout << endl << endl <<  "Enter i and j: ";
		cin >> i >> j;

		cout << endl << "Elements from i to j: ";
		z = txt1(i,j);
		if(!z) cout << "ERROR";

		cout << endl << endl << "Repeat? (y/n)" << endl;
		cin >> check;
		system("cls");
	}	while (check!='n');

	return 0;
}