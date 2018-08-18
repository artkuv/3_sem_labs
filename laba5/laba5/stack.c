#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"

void listInit(ListDescriptor *descr) //принимает указатель на структуру с вершиной стека и зануляющая этот указатель
{
	descr->head=NULL;
}

int AddItem(ListDescriptor *descr)
{
	struct listItem *temp;

	if(!(temp=(struct listItem *)malloc(sizeof(struct listItem))))
	{
		puts("Memory allocation error");
		return 1;
	}

	if(setInfo(&temp->data))
	{
		puts("error of filling data");
		return 1;
	}

	temp->next=descr->head;
	descr->head=temp;

	return 0;
}

void ShowList(ListDescriptor *descr)
{
	struct listItem *temp;

	temp=descr->head;
	while(temp!=NULL)
	{
		showInfo(&temp->data);
		temp=temp->next;
	}
}
/*
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
*/
void freeList(struct listItem *item) //recursive delete
{
	if(item){ //if an element exists
		freeList(item->next); //go deeper (to the listItem bottom)
		free(item); //free elements from bottom to the top
	}
}

void ClearAll(ListDescriptor *descr)
{
	freeList(descr->head); //pointer to listItem top
}
