#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define M 11
#define M1 50

typedef struct info
{ char *name;//���	
int cost;//�����
int id;
union inf {
	char genre[M];//����
	int maxpl;//��� ���
} inf;
} info;

int SetInfo(struct info*);//���� ������
void ShowInfo(struct info*, int);//����� ���
void search_igra(struct info*, int*);//����� ����
void search_to_delete(struct info*, int*);//����� ��� ����
void SaveInfoToFile (FILE* f, struct info *);//������ 
int readInfoFromFile (FILE* f, struct info *);//������
