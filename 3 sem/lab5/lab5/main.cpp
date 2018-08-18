#pragma once
#include "learner.h"
#include "student.h"
#include "graduate.h"
#include "pupil.h"

void myterminate()
{
	cout << "temrinate";
}

void f(char *err) throw(Exeption)
{
	if(*err) throw Input(1,err);
}

int main()
{
	set_terminate(myterminate);
	int check1, check2, check3, i, flag=0;
	char stn [NAME], sts[SNAME], num[10];
	char *err;
	err="invalid values";
	double sr;

	Student S;
	Student S1;
	Pupil P;
	Pupil P1;
	Graduate G;
	Graduate G1;

	cout << "Pupil 1: " << endl;
	cin >> P;
	system("cls");
	cout << "Pupil 2: " << endl;
	cin >> P1;
	system("cls");
	
	cout << "Student 1: " <<endl;
	cin >> S;
	system("cls");
	cout << "Student 2: " <<endl;
	cin >> S1;
	system("cls");
	
	cout << "Graduate 1: " <<endl;
	cin >> G;
	system("cls");
	cout << "Graduate 2: " <<endl;
	cin >> G1;
	system("cls");
	
	do{
		system("cls");

		P.printPup();
		cout << P << endl;
		cout << P1 << endl << endl << endl << endl; 
		
		S.printStud();
		cout << S << endl;
		cout << S1 << endl << endl << endl << endl; 
		
		G.printGrad();
		cout << G;
		cout << G1 << endl;
		
		cout << endl << endl << "1.Change Pupil" << endl << "2.Change Student" << endl << "3.Change Graduate" << endl << "0.Close program" << endl;
		cin >> check1;
		if(check1<0 || check1>3)
			throw 0;

		/*do
		{
			try
			{
				cout << endl << endl << "1.Change Pupil" << endl << "2.Change Student" << endl << "3.Change Graduate" << endl << "0.Close program" << endl;

				cin >> check1;
				if(check1<0 || check1>3)
				{
					flag=1;
					throw Input(1,err);
				}
				else 
					flag=0;
			}
			catch(Input &EX)
			{
				cout << "Error #" << EX.error << " - " << EX.name;
			}
		}
		while(flag==1);*/
		
		cout << "Choose the object: " << endl;
		cin >> check2;

		cout << endl << "1.Year" << endl << "2.Name" << endl << "3.Surname" << endl;

		switch(check1)
		{
		case 1:
			do
			{
				try
				{
					cout << "4.Class" << endl << "5.Mark" << endl;
					cin >> check3;
					if(check3<0 || check3>5)
					{
						flag=1;
						f(err);
					}
					else 
						flag=0;
				}
				catch(Input &EX)
				{
					cout << "Error #" << EX.error << " - " << EX.name << endl;
				}
			}
			while(flag==1);

			rewind(stdin);

			switch(check3)
			{
			case 1:
				cout << "Year: ";
				cin >> i;
				if(check2 == 1)
					P.SetY(i);
				if(check2 == 2)
					P1.SetY(i);
				break;

			case 2:
				cout << "Name: ";
				cin >> stn;
				if(check2 == 1)
					P.SetN(stn);
				if(check2 == 2)
					P1.SetN(stn);
				break;
				
			case 3:
				cout << "Surname: ";
				cin >> sts;
				if(check2 == 1)
					P.SetS(sts);
				if(check2 == 2)
					P1.SetS(sts);
				break;

			case 4:
				cout << "Class: ";
				cin >> i;
				if(check2 == 1)
					P.SetCl(i);
				if(check2 == 2)
					P1.SetCl(i);
				break;

			case 5:
				cout << "Mark: ";
				cin >> sr;
				if(check2 == 1)
					P.SetSr(sr);
				if(check2 == 2)
					P1.SetSr(sr);
				break;
			
			default:
				cout << "No such element" << endl;
				break;
			}

			break;

		case 2:
			
			do
			{
				try
				{
					cout << "4.Curse" << endl << "5.Num" << endl;
					cin >> check3;
					try{
					if(check3<0 || check3>5)
					{
						flag=1;
						throw Input(1,err);
					}
					else 
						flag=0;
					}
					catch(Input &EX)
					{
						cout << endl << "first exception" << endl;
						throw;
					}
				}
				catch(Input &EX)
				{
					cout << "Error #" << EX.error << " - " << EX.name << endl;
					cout << "second exception" << endl << endl;
				}
			}
			while(flag==1);

			rewind(stdin);

			switch(check3)
			{
			case 1:
				cout << "Year: ";
				cin >> i;
				if(check2 == 1)
					S.SetY(i);
				if(check2 == 2)
					S1.SetY(i);
				break;

			case 2:
				cout << "Name: ";
				cin >> stn;
				if(check2 == 1)
					S.SetN(stn);
				if(check2 == 2)
					S1.SetN(stn);
				break;
				
			case 3:
				cout << "Surname: ";
				cin >> sts;
				if(check2 == 1)
					S.SetS(sts);
				if(check2 == 2)
					S1.SetS(sts);
				break;

			case 4:
				cout << "Curse: ";
				cin >> i;
				if(check2 == 1)
					S.SetC(i);
				if(check2 == 2)
					S1.SetC(i);
				break;

			case 5:
				cout << "Num: ";
				cin >> num;
				if(check2 == 1)
					S.SetNum(num);
				if(check2 == 2)
					S1.SetNum(num);
				break;

			default:
				cout << "No such element" << endl;
				break;
			}

			break;

		case 3:
			cout << "4.Graduation year" << endl << "5.Speciality" << endl;
			cin >> check3;

			rewind(stdin);

			switch(check3)
			{
			case 1:
				cout << "Year: ";
				cin >> i;
				if(check2 == 1)
					G.SetY(i);
				if(check2 == 2)
					G1.SetY(i);
				break;

			case 2:
				cout << "Name: ";
				cin >> stn;
				if(check2 == 1)
					G.SetN(stn);
				if(check2 == 2)
					G1.SetN(stn);
				break;
				
			case 3:
				cout << "Surname: ";
				cin >> sts;
				if(check2 == 1)
					G.SetS(sts);
				if(check2 == 2)
					G1.SetS(sts);
				break;

			case 4:
				cout << "Graduation year: ";
				cin >> i;
				if(check2 == 1)
					G.SetGrad(i);
				if(check2 == 2)
					G1.SetGrad(i);
				break;

			case 5:
				cout << "Speciality: ";
				char **speciality = new char*[10], spec[SNAME];
				int i = 0;
				do {
					rewind(stdin);
					cin.getline(spec,SNAME);
					speciality[i] = new char[strlen(spec) + 1];
					strcpy_s(speciality[i], strlen(spec) + 1, spec);
					i++;
				} while (strcmp(speciality[i - 1], "") != 0);
				if(check2 == 1)
					G.SetSpec(speciality);
				if(check2 == 2)
					G1.SetSpec(speciality);
				break;
			}

			break;

		case 0:
			break;
		}
	}while(check1);
	return 0;
}