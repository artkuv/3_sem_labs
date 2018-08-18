#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define M 11
#define M1 50

typedef struct serial
{
	int kolvo;
	int id;
	char *nazv;
	union dop
	{
		char data[8];
		int sezon;
	}dop;
}serial;

int SetInfo(struct info*);//ввод информ
void ShowInfo(struct info*, int);//вывод инф
void search_igra(struct info*, int*);//поиск игры
