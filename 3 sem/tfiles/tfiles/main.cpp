#include<iostream>
#include"Header.h"
#include<fstream>
using namespace std;

int main()
{
	Auto obj[SIZE];
	obj[SIZE].add();
	/*Auto obj[SIZE] = {
		Auto("BMW",1999),
		Auto("Wolswagen",2000),
		Auto("Lada",2001),
		Auto("Niva",2002),
		Auto("Opel",2003)
	};*/
	char* nameFile = "TXTFile.txt";
	char* nameFile1 = "BINFile.bin";
	for (int i = 0; i < SIZE; i++)
	{
		obj[i].writeTXT(obj, nameFile);
		obj[i].readTXT(nameFile);
		obj[i].writeBIN(obj, nameFile1);
		obj[i].readBIN(nameFile1);
	}
	return 0;
}