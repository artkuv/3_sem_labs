#include<iostream>
using namespace std;

class mass
{
	int *ms;					      
	int size;					      

public:

	mass();					      //конструктор по умолчанию 
	mass(const mass & obj);       //конструктор копирования
	explicit mass(int n);         //конструктор explicit с параметром

	~mass();					  //деструктор

	void setmass();               //ввод массива с клавиатуры
	void getmass();				  //вывод массива на экран 
	mass Repeating();			  //удаление повторных элементов в массиве
	
	mass operator = (const mass a);     //перегруженный оператор присваивания
	mass operator * (mass a);	  //перегруженный оператор пересечения массивов 
	const mass operator + (mass a);	  //перегруженный оператор сложения массивов 
	mass operator > (mass a);	  //перегруженный оператор сравнения массивов 
	mass operator ++ ();		  //перегруженный оператор ++(преф) 
	mass operator -- ();		  //перегруженный оператор --(преф)
	mass operator ++ (int x);	  //перегруженный оператор ++(пост) 
	mass operator -- (int x);	  //перегруженный оператор --(пост) 
};