#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
   ifstream file("input.txt");
   vector<string> v; //������ �����
   string S;  //����������� ����� �� �����
 
   while(getline(file, S, ' '))  v.push_back(S);  //���������� � ������ � ��������� �����������
 
   for (unsigned int i=0;i<v.size();i++) cout<<v.at(i)<<" "; //����� ������� �� �����
   system("pause");
}