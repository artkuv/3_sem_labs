#include "EVM.h"
#include "port.h"
#include "stationar.h"
#include <iostream>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <set>
#include <iterator>

using namespace std;


template <typename Tmp>
void menu(multiset<Tmp> a)
{
	int choose;
	setlocale(0, "");
	do
	{
		system("cls");

		cout << "1. Add." << endl
			<< "2. Show." << endl
			<< "3. Del." << endl
			<< "4. Clear." << endl
			<< "5. Find." << endl
			<< "0. Exit." << endl;

		cout << endl << "Your choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			Tmp obj;
			cin >> obj;
			cout << endl;
			a.insert(obj);
			break;
		}
		case 2:
		{
			copy(a.begin(), a.end(), ostream_iterator<Tmp>(cout, " "));
			system("pause");
			break;
		}
		case 3:
		{
			Tmp num;
			cout << "Enter the object to delete. ";
			cin >> num;
			multiset<Tmp> temp;
			auto it = a.begin();
			while (it != a.end())
			{
				if ((Tmp)*it == num)
					temp.insert(*it);
				it++;
			}
			it = temp.begin();
			copy(temp.begin(), temp.end(), ostream_iterator<Tmp>(cout, " "));

			system("pause");
			copy(temp.begin(), temp.end(), ostream_iterator<Tmp>(cout, "\n"));
			cout << "What el you want to delete: ";
			int choice;
			cin >> choice;
			it = temp.begin();
			auto last = it;
			while (choice)
			{
				it++;
				choice--;
			}
			last++;
			a.erase(it, last);
			system("pause");
			break;
		}
		case 4:
		{
			a.clear();
			break;
		}
		case 5:
		{
			Tmp key;
			cin >> key;
			auto it = a.begin();
			it = (a.find(key));
			cout << *it;
			system("pause");
			break;
		}
		case 0:
			break;
		}
	} while (choose);
}


int main()
{
	multiset<double> Fa;
	multiset<monoblock> Ma;
	multiset<EVM> Ea;
	multiset<Stationar> Sa;
	multiset<port> Pa;

	int choose;

	cout << "Select class:" << endl
		<< "1. Double." << endl
		<< "2. EVM." << endl
		<< "3. Stationar." << endl
		<< "4. Portable." << endl
		<< "5. Monoblock" << endl
		<< "6. Exit" << endl;

	cout << endl << "Choose: ";
	cin >> choose;

	system("cls");

	switch (choose)
	{
	case 1:
		menu(Fa);
		break;
	case 2:
		menu(Ea);
		break;
	case 3:
		menu(Sa);
		break;
	case 4:
		menu(Pa);
		break;
	case 5:
		menu(Ma);
		break;
	case 6:
		break;
	}

	system("pause");
	return 0;
}
