#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
   ifstream file("input.txt");
   vector<string> v; //Вектор строк
   string S;  //Считываемое слово из файла
 
   while(getline(file, S, ' '))  v.push_back(S);  //Считывание в вектор с указанием разделителя
 
   for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<" "; //Вывод вектора на экран
   system("pause");
}