#include <iostream>
#include <string>
using namespace std;

class String
{
	char *txt;
	int size;

public:
				          
	String(int n);        
	String(char *s="");
	String(const String &obj); 
	~String();					      
              
	int GetString();				  

	String& operator = (const String &obj);   
	String operator + (const String &obj);	  
	friend String operator + (const char *a,const String &obj);
	String operator + (const char *a);

	void operator == (const String &obj);	 

	void operator ++ ();			  
	void operator -- ();			  
	void operator ++ (int x);			
	void operator -- (int x);	
	int operator += (int x);	

	int operator () (int i, int j);
};