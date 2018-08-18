#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"

void listInit(ListDescriptor *descr) //принимает указатель на структуру с вершиной стека и зануляющая этот указатель
{
	descr->head=NULL;
}

int AddItem(struct ListDescriptor *descr)
{
	 int a=0,flag;
	 struct listItem *temp;

	 temp=(struct listItem *)malloc(sizeof(struct listItem));
	 if(!temp) {
		puts("ALLOC ERROR");
		return 1;
	 }

	if(setInfo(&temp->data))
	{
		puts("error of filling data");
		return 1;
	}

	if(descr->head) 
	{
		puts("add in:\n 1-end\n 0-begin\n");

		do
		{
			fflush(stdin);
			flag=scanf_s("%d",&a);
			if(!flag || (flag && (a>1 || a<0)))
			{
				puts("Reenter number");
				flag=0;
			}
		}
		while(!flag);
	}

	if(!descr->head)
	 {
		descr->head=temp;
		temp->prev=temp;
		temp->next=temp;
	 }
	else
	{
		temp->next=descr->head;
		temp->prev=descr->head->prev;
		descr->head->prev=temp;
		temp->prev->next=temp;

		if(a==0)			
			descr->head=temp;
	}
	 return 0;
}

void showItem(struct listItem *item) //recursive delete
{
	if(item){ //if an element exists
		showItem(item->next); //go deeper (to the listItem bottom)
		showInfo(&item->data);
	}
}

void ShowList(ListDescriptor *descr)
{
	struct listItem *temp;
	int flag,a;

	puts("list from:\n 1-end\n 0-begin\n");

	do
	{
		fflush(stdin);
		flag=scanf_s("%d",&a);
		if(!flag || (flag && (a>1 || a<0)))
		{
			puts("Reenter number");
			flag=0;
		}
	}
	while(!flag);

	

	if(a==0)
	{
		temp=descr->head;
		do
		{
			showInfo(&temp->data);
			temp=temp->next;
		}while(temp!=descr->head);
	}
	else
	{
		temp=descr->head->prev;
		do
		{
			showInfo(&temp->data);
			temp=temp->prev;
		}while(temp!=descr->head->prev);
	}
}

int FindItem(ListDescriptor descr)
{
	return 0;
}

int DeleteItem(ListDescriptor *descr)
{
	return 0;
}
int SaveToFile(ListDescriptor descr)
{
	return 0;
}

int GetFromFile(ListDescriptor *descr)
{
	return 0;
}

void ClearAll(ListDescriptor *descr)
{
	struct listItem *temp;

	if(descr->head)
	{
		temp=descr->head->prev;

		while(descr->head!=temp)
		{
			temp=temp->prev;
			free(temp->next);	
		}
		free(descr->head);
	}
}