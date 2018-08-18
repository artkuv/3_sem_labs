#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem
{
	struct serial data;
	struct listItem *next;
	struct listItem *prev;
}listItem;

#ifdef LIST_QUEUE
typedef struct ListDescriptor
{
	struct listItem *head;
	struct listItem *tail;
}ListDescriptor;
#else
typedef struct ListDescriptor
{
	struct listItem *head;
}ListDescriptor;
#endif


void listInit(ListDescriptor *descr);

int AddItem(ListDescriptor *descr); 
void ShowList(ListDescriptor *descr);
int FindItem(ListDescriptor descr);
int DeleteItem(ListDescriptor *descr); 
int SaveToFile(ListDescriptor descr); 
int GetFromFile(ListDescriptor *descr);
void ClearAll(ListDescriptor *descr);