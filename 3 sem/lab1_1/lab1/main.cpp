#include"class.h"

int main()
{
	char check;
	do {
		int size1;
		cout << "Enter the size of array #1" << endl;
		cin >> size1;
		mass ms1(size1);											//����������� c ����������� 

		cout << "Input elements in mass: " << endl; 
		ms1.setmass();		
		ms1 = ms1.Repeating();	   
		cout << "After correcting " << endl;
		ms1.getmass();		

		int size2;
		cout << endl << "Enter the size of array #2" << endl;
		cin >> size2;
		mass ms2(size2);

		mass ms5(size2);											//����������� explicit � ����������    	
		cout << "Input elements in mass: " << endl; 
		ms2.setmass();
		ms5 = ms2.Repeating();
		cout << "After correcting " << endl;
		ms5.getmass();
		
		mass ms3;
		ms3 = ms1 * ms2;											//����������� �������� 
		cout << endl << "Array #3" << endl;
		ms3.getmass();
											     	
		mass ms4;													//�������� ��������
		ms4 = ms1 + ms2;
		cout << endl << "Array #4" << endl;
		ms4.getmass();
		
		cout << "\nComparison" << endl;
		ms1 > ms2;													//��������� �������� 

		cout << "\nms1++\n" << endl;
		ms1++;														//������. ����. ������� ms1 
		ms1.getmass();

		cout << "\nms1--\n" << endl;
		ms1--;														//������. ����. ������� ms1 
		ms1.getmass();

		cout << "\n++ms2\n" << endl;
		++ms2;														//������. ����. ������� ms2 
		ms2.getmass();

		cout << "\n--ms2\n" << endl;								//������. ����. ������� ms2 
		--ms2;
		ms2.getmass();

		cout << "Repeat? (y/n)" << endl;
		rewind(stdin);
		cin >> check;
		system("cls");
	}
	while (check!='n');
	return 0;
}