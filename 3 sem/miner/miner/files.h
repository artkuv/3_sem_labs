#include "exeption.h"

void finez(int id)
{
	streampos p;
	int count, buff;

	ifstream fin("statsez.txt",ios_base::in);

	p=fin.tellg();
	fin >> count;
	fin >> buff;

	if(buff==id)
	{
		ofstream fout("statsez.txt",ios_base::out);
		count++;
		fin.seekg(p);	
		fout << count << " " << id << endl << "\n";
		fout.close();
	}
	else  
	{
		ofstream fout("statsez.txt",ios_base::app);
		fout << "1 " << id << "\n";
		fout.close();
	}

	fin.close();
}

void finmed(int id)
{
	streampos p;
	int count, buff;

	ifstream fin("statsmed.txt",ios_base::in);

	p=fin.tellg();
	fin >> count;
	fin >> buff;

	if(buff==id)
	{
		ofstream fout("statsmed.txt",ios_base::out);
		count++;
		fin.seekg(p);	
		fout << count << " " << id << endl << "\n";
		fout.close();
	}
	else  
	{
		ofstream fout("statsmed.txt",ios_base::app);
		fout << "1 " << id << "\n";
		fout.close();
	}

	fin.close();
}

void finhard(int id)
{
	streampos p;
	int count, buff;

	ifstream fin("statshard.txt",ios_base::in);

	p=fin.tellg();
	fin >> count;
	fin >> buff;

	if(buff==id)
	{
		ofstream fout("statshard.txt",ios_base::out);
		count++;
		fin.seekg(p);	
		fout << count << " " << id << endl << "\n";
		fout.close();
	}
	else  
	{
		ofstream fout("statshard.txt",ios_base::app);
		fout << "1 " << id << "\n";
		fout.close();
	}

	fin.close();
}

void fin(int id)
{
	streampos p;
	int count, buff;

	ifstream fin("stats.txt",ios_base::in);

	p=fin.tellg();
	fin >> count;
	fin >> buff;

	if(buff==id)
	{
		ofstream fout("stats.txt",ios_base::out);
		count++;
		fin.seekg(p);	
		fout << count << " " << id << endl << "\n";
		fout.close();
	}
	else  
	{
		ofstream fout("stats.txt",ios_base::app);
		fout << "1 " << id << "\n";
		fout.close();
	}

	fin.close();
}

void chekez()
{
	ifstream fin("statsez.txt");
	vector<int> v; 
	int S;
 
    while(fin >> S)  v.push_back(S);  //Считывание в вектор

    for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<"\n"; //Вывод вектора на экран
	fin.close();
}

void chekmed()
{
	ifstream fin("statsmed.txt");
	vector<int> v; 
	int S;
 
    while(fin >> S)  v.push_back(S);  //Считывание в вектор

    for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<"\n"; //Вывод вектора на экран
	fin.close();
}

void chekhard()
{
	ifstream fin("statshard.txt");
	vector<int> v; 
	int S;
 
    while(fin >> S)  v.push_back(S);  //Считывание в вектор

    for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<"\n"; //Вывод вектора на экран
	fin.close();
}

void chekself()
{
	ifstream fin("stats.txt");
	vector<int> v; 
	int S;
 
    while(fin >> S)  v.push_back(S);  //Считывание в вектор

    for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<"\n"; //Вывод вектора на экран
	fin.close();
}