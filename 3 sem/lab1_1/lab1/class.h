#include<iostream>
using namespace std;

class mass
{
	int *ms;					      
	int size;					      

public:

	mass();					      //����������� �� ��������� 
	mass(const mass & obj);       //����������� �����������
	explicit mass(int n);         //����������� explicit � ����������

	~mass();					  //����������

	void setmass();               //���� ������� � ����������
	void getmass();				  //����� ������� �� ����� 
	mass Repeating();			  //�������� ��������� ��������� � �������
	
	mass operator = (const mass a);     //������������� �������� ������������
	mass operator * (mass a);	  //������������� �������� ����������� �������� 
	const mass operator + (mass a);	  //������������� �������� �������� �������� 
	mass operator > (mass a);	  //������������� �������� ��������� �������� 
	mass operator ++ ();		  //������������� �������� ++(����) 
	mass operator -- ();		  //������������� �������� --(����)
	mass operator ++ (int x);	  //������������� �������� ++(����) 
	mass operator -- (int x);	  //������������� �������� --(����) 
};