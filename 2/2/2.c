/*2. Структура содержит информацию о пассажирах: номер рейса (число), фамилию (указатель), вложенную структуру – дату выезда (строка фиксированной длины) и количество минут в пути.
Найти пассажиров заданного рейса. Удалить пассажиров заданной фамилией.
Кульчицкий Артем 650503 Вариант 14*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define M 11
#define m 50

typedef struct pass
{ 
	int number;
	char *name;
	struct info
	{
		char date[M];
		int duration;
	} inf;
}pass;

void input(pass *ms, int );
void output(pass *ms, int );
void search_number(pass *ms, int );
void search_to_delete(pass *ms, int *);


int main()
{ 
	int flag, i, ans, N;
	pass *ms;

	printf("enter number of passs: ");
	do 
	{
		flag=scanf("%d", &N);
		if(!flag || N<=0)
			puts("retry");
	} while(!flag || N<=0);

	ms=(struct pass*)malloc(N*sizeof(struct pass));
	if(!ms)
	{
		puts("ERROR");
		return 0;
	}

	for(i=0; i<N; i++) 
	{
		(ms+i)->name=(char *)malloc(m*sizeof(char));
		if(!(ms+i)->name) 
		{
			puts("ERROR");
			free(ms);
			return 0;
		}
	}

	for(i=0; i<N; i++)
	{
		input(ms, i);
		output(ms, i);
	}

	search_number(ms,N);
	search_to_delete(ms,&N);
	for(i=0; i<N; i++)
		 output(ms, i);

	for(i=0; i<N; i++)
		free((ms+i)->name);
	free(ms);
	return 0;
}
void input(pass *ms, int i)
{ 
	int l, flag;
	printf("\nenter the name of pass %d : \n", (i+1));
	gets((ms+i)->name);
	printf("\nenter the number of it %d : \n", (i+1));
	do 
	{
	flag=scanf("%d", &(ms+i)->number);
	if(!flag || (ms+i)->number<=0)
		puts("retry");
	} while(!flag || (ms+i)->number<=0);
	
} 
void output(pass *ms, int i)
{	
	printf("\npass %d\n", i+1);
	printf("name: %s\n", (ms+i)->name);
	printf("number of it: %d\n", (ms+i)->number);	
}
void search_number( pass *ms, int N)
{ 
	int i,n,c,flag;
	printf("\nenter the number : \n");
	do 
	{
	flag=scanf("%d", &c);
	if(!flag || c<=0)
		puts("retry");
	} while(!flag || (ms+i)->number<0);
	for(i=0; i<N; i++)
		if((ms+i)->number==c)
		{
			output(ms,i);
		}
}
void search_to_delete(pass *ms, int *N)
{ 
	int i, j;
	char *str;
	str = (char*)malloc(m*sizeof(char));
	if(!str) return;
	printf("\nenter the name of pass: ");
	gets(str);
	for(i=0; i<*N; i++)
		if(!strcmp((ms+i)->name,str))
		{
			(*N)--;
			for(j=i; j<*N; j++) 
			{
				strcpy((ms+j)->name, (ms+(j+1))->name);
				(ms+j)->number=(ms+(j+1))->number;
			}
			free((ms+*N)->name);
			i--;
		}
	free(str);
}