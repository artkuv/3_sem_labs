#include "class.h"
#include <fstream>

void main()
{
	car ms[3], ms2[3];
	ofstream write;
	ifstream read;
	string str;
	int check, flag = 0;

	do{
		system("cls");
		cout << "1. Input info" << endl;
		cout << "2. Write to txtFile" << endl;
		cout << "3. Read from txtFile" << endl;
		cout << "4. Show information in txtFile" << endl;
		cout << "5. Write to binFile" << endl;
		cout << "6. Read from binFile" << endl;
		cout << "7. Show information in binFile" << endl;
		cout << "0. Close program" << endl;
		cin >> check;
		
		switch(check)
		{

		case 1:
			for(int i = 0; i < 3; i++)
			{
				system("cls");
				cin >> ms[i];
				ms2[i]=ms[i];
			}
			flag = 1;
			break;

		case 2:
			write.open("car.txt");
		
			if(!flag)
			{
				cout << "No information to write" << endl;
				system("pause");
				break;
			}

			if(!write.is_open())
			{
				cout << "Can't open the File";
				system("pause");
				break;
			}

			for(int i = 0; i < 3; i++)
				write << ms[i];

			write.close();
			break;

		case 3:
			read.open("car.txt");

			if(!read.is_open())
			{
				cout << "Can't open the File";
				system("pause");
				break;
			}

			for(int i = 0; i < 3; i++)
				read >> ms[i];
		
			read.close();
			break;

		case 4:
			system("cls");
			ms[1].print();
			for(int i = 0; i < 3; i++)
			{
				cout << ms[i];
			}
			system("pause");
			break;

		case 5:

			if(!flag)
			{
				cout << "No information to write" << endl;
				system("pause");
				break;
			}

			write.open("car.bin",ios::binary | ios_base::out);
			if(!write.is_open())
			{
				cout << "Can't open the File";
				system("pause");
				break;
			}

			for(int i = 0; i < 3; i++)
					write.write((char*)&ms2[i], sizeof(ms2[i]));

			write.close();
			break;

		case 6:
			read.open("car.bin",ios::binary | ios_base::in);

			if(!read.is_open())
			{
				cout << "Can't open the File";
				system("pause");
				break;
			}

			for(int i = 0; i < 3; i++)
				read.read((char*)&ms2[i], sizeof(ms2[i]));

			read.close();
			break;

		case 7:
			system("cls");
			ms2[1].print();
			for(int i = 0; i < 3; i++)
			{
				cout << ms2[i];
			}
			system("pause");
			break;

		case 0:
			check = 0;
			break;
		}
	}while(check);
	return;
}