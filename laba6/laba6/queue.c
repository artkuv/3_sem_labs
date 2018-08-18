#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"

void listInit(ListDescriptor *descr) //принимает указатель на структуру с вершиной стека и зануляющая этот указатель
{
	descr->head=NULL;
	descr->tail=NULL;
}

int AddItem(struct ListDescriptor *descr)
{
	 struct listItem *temp;

	 temp=(struct listItem *)malloc(sizeof(struct listItem));
	 if(!temp) {
		puts("ALLOC ERROR");
		return 1;
	 }

	 setInfo(&temp->data);

	 if(!descr->head)
	 {
		descr->head=temp;
		descr->tail=temp;
		temp->next=NULL;
	 }
		else
	 {
		descr->tail->next=temp;
		descr->tail=temp;
		temp->next=NULL;
	 }

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
	struct listItem *temp=descr->head;
	while(descr->head!=descr->tail)
	{
		descr->head=descr->head->next;
		free(temp);
		temp=descr->head;
	}
	if(descr->tail) free(descr->tail);
}