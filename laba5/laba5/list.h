#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem
{
	struct serial data;
	struct listItem *next;
}listItem;

typedef struct ListDescriptor
{
	struct listItem *head;
}ListDescriptor;

void listInit(ListDescriptor *descr);

int AddItem(ListDescriptor *descr); 
void ShowList(ListDescriptor *descr);
int FindItem(ListDescriptor descr);
int DeleteItem(ListDescriptor *descr); 
int SaveToFile(ListDescriptor descr); 
int GetFromFile(ListDescriptor *descr);
void ClearAll(ListDescriptor *descr);