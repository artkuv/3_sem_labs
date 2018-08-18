#include "list.h"

#define M 11
#define M1 50

void listInit(struct ListDescriptor *des)//зануление
{
	des->head=NULL;
}

int AddItem(struct ListDescriptor *des)//добавление объект
{
	struct stack *cur;//переменная
	cur=(struct stack *)malloc(sizeof(struct stack));
if(!cur) 
{
	puts("ERROR");
	return 1;
}

if(SetInfo(&cur->data)) return 1;
cur->next=des->head;//что бы кур указ на голову
des->head=cur;//станов головой
return 0;
}



void freeList(struct stack *item) //рекурс удал
{
	if (item)
	{ 
		freeList(item->next); //идет в глубь
		free(item); //очищ элем снизу вверх
	}
}

void ClearAll(struct ListDescriptor *des)
{
	freeList(des->head); //pointer to stack top
}