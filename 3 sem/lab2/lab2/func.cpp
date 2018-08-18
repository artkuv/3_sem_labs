#include "class.h"

String::String(int length)
{
	this->size = length;
	this->txt = new char[this->size + 1];
}

String::String(char *s)
{
	this->size = strlen(s);
	this->txt = new char[this->size + 1];
	strcpy(txt,s);
}

String::String(const String &obj)
{
	this->size = strlen(obj.txt);
	this->txt = new char[this->size+1];

	strcpy(this->txt,obj.txt);
}

String::~String()
{
	delete[] txt;
	txt = NULL;
}

int String::GetString()
{
	for(int i = 0; i < this->size; i++)
	cout << this->txt[i];
	return this->size;
}

String& String::operator = (const String &obj)
{

	if (this != &obj)
	{
		delete[] this->txt;
	
		this->txt = new char[strlen(obj.txt)+1];
		this->size = obj.size;
		strcpy(txt,obj.txt);
	}
	return *this;
}

String String::operator + (const String &obj)
{
	unsigned int length;
	length = strlen(this->txt) + strlen(obj.txt);
	String temp(length+1);
	strcpy(temp.txt,this->txt);
	strcat(temp.txt," ");
	strcat(temp.txt,obj.txt);	
	return temp;
}

String String::operator + (const char *a)
{
	unsigned int length;
	length = strlen(this->txt) + strlen(a);
	String temp(length+1);
	strcpy(temp.txt,this->txt);
	strcat(temp.txt," ");
	strcat(temp.txt,a);
	return temp;
}

String operator + (const char *a,const String &obj)
{
	unsigned int length;
	length = strlen(a) + obj.size;
	String temp(length+1);
	strcpy(temp.txt,a);
	strcat(temp.txt," ");
	strcat(temp.txt,obj.txt);
	return temp;
}

void String::operator == (const String &obj)
{
	int length;

	length = strlen(this->txt) - strlen(obj.txt);
	if(length > 0)
		cout << endl << "txt1 > txt2" << endl;

	length = strlen(this->txt) - strlen(obj.txt);
	if(length < 0)
		cout << endl << "txt1 < txt2" << endl;

	length = strlen(this->txt) - strlen(obj.txt);
	if(length == 0)
		cout << endl << "txt1 = txt2" << endl;
}

void String::operator ++ ()
{
	unsigned int i;

	for(i = 0; i < strlen(this->txt); i++)
		this->txt[i]++;
}

void String::operator -- ()
{
	unsigned int i;

	for(i = 0; i < strlen(this->txt); i++)
		this->txt[i]--;
}

void String::operator ++ (int x)
{
	unsigned int i;

	for(i = 0; i < strlen(this->txt); i++)
		this->txt[i]++;
}

void String::operator -- (int x)
{
	unsigned int i;

	for(i = 0; i < strlen(this->txt); i++)
		this->txt[i]--;
}

int String::operator()(int i, int j)
{
	if(i > this->size || j > this->size) return 0;

	for(i;i<=j;i++)
		cout << this->txt[i-1];
}

int String::operator += (int x)
{
	unsigned int i;
	for(i = 0; i < strlen(this->txt); i++)
	{
		if((this->txt[i]+x)>127)
		{
			cout << "error";
			return 1;
		}
	}
	for(i = 0; i < strlen(this->txt); i++)
		this->txt[i]+=x;
}