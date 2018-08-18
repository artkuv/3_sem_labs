#include "func.h"

int settings(int men)
{
	int i;

	cout << "Select difficulty: \n1)easy (9X9, 3 mines) \n2)medium (13X13, 40 mines) \n3)hard (19X19, 13 mines) \n4)your \n0)back\n";
	cin >> i;
	switch(i)
	{
		case(1): {N=9; M=10; return 0;break;};
		case(2): {N=13; M=40; return 0;break;};
		case(3): {N=19; M=110; return 0;break;};
		case(4):
		{
			system("cls");
			cout << "Enter size of field N (N X N):" << endl;
			cin >> N;
			cout << "Enter number of mines (max N*N-1):" << endl;
			cin >> M;
			return 0;
			break;
		};
		case(0): return 2; break;
		default: break;
	}
}

void rules()
{
	int i;
	cout << "÷ель игры : Ќайти пустые €чейки, но не трогать €чейки, содержащие мины. „ем \nбыстрее вы очистите всю доску, тем лучше будет результат. \n";
	cout << "ѕравила игры: \n≈сли открыта €чейка с миной, игра проиграна. ≈сли открыта пуста€ €чейка, игра \nпродолжаетс€. ";
	cout << "≈сли в €чейке указано число, оно показывает, сколько мин скрыто в восьми €чейках вокруг данной. Ёто число помогает пон€ть,где наход€тс€ безопасные€чейки.";
	cout << "\npress any number to go back:";
	cin >> i;
}

void menu()
{
	int men;
	do
	{
		cout << "1)new game \n2)stats \n3)rules \n0)exit \n";
		cin >> men;
		switch(men)
		{
		case(1): {system("cls"); men=settings(men); system("cls");} break;
		case(2): 
			{
				system("cls");
				int i;
				cout << "1)easy \n2)medium \n3)hard \n4)self \n0)back \n";
				cin >> i;
				switch(i)
				{
				case(1): {system("cls"); chekez(); _getch();} break;
				case(2): {system("cls"); chekmed(); _getch();} break;
				case(3): {system("cls"); chekhard(); _getch();} break;
				case(4): {system("cls"); chekself(); _getch();} break;
				case(0): ;
				default: break;
				}
				 system("cls");
			}break;
		case(3): {system("cls"); rules(); system("cls");} break;
		case(0): exit(0);
		default: system("cls"); break;
		}
	}while(men!=0);
}