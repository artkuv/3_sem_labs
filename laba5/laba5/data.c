#include "list.h"
#include <stdio.h>
#include <malloc.h>

#define N 50

int setInfo(struct serial *item)
{
	int flag;
	puts("enter number of series");
	do
	{
		fflush(stdin);
		flag=scanf_s("%d", &item->kolvo);
		if(!flag || item->kolvo<1)
			puts("reenter number");
	}
	while(!flag);
	
	puts("enter name of serial");
	if(!(item->nazv=(char*)malloc(N*sizeof(char))))
	{
		puts("Memory allocation error");
		return 1;
	}
	fflush(stdin);
	gets_s(item->nazv,50);
	
	puts("enter data of film");
	fflush(stdin);
	gets(item->dop.data);
	puts("enter number of seazons");
	do
	{
		fflush(stdin);
		flag=scanf_s("%d", &item->dop.sezon);
		if(!flag || item->dop.sezon<1)
			puts("reenter number");
	}
	while(!flag);
	return 0;
}

void showInfo(struct serial *item)
{
	printf("number of series: %d \n",item->kolvo);
	printf("name of serial: %s \n",item->nazv);
	printf("data of film: %s \n",item->dop.data);
	printf("number of seazons: %d \n\n",item->dop.sezon);
}