#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define M 11
#define M1 50

typedef struct info
{ char *name;//имя	
int cost;//стоим
int id;
union inf {
	char genre[M];//жанр
	int maxpl;//кол игр
} inf;
} info;

int SetInfo(struct info*);//ввод информ
void ShowInfo(struct info*, int);//вывод инф
void search_igra(struct info*, int*);//поиск игры
void search_to_delete(struct info*, int*);//поиск для удал
void SaveInfoToFile (FILE* f, struct info *);//сохран 
int readInfoFromFile (FILE* f, struct info *);//чтение
