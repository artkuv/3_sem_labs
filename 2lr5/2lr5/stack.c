#include "list.h"

#define M 11
#define M1 50

void listInit(struct ListDescriptor *des)//���������
{
	des->head=NULL;
}

int AddItem(struct ListDescriptor *des)//���������� ������
{
	struct stack *cur;//����������
	cur=(struct stack *)malloc(sizeof(struct stack));
if(!cur) 
{
	puts("ERROR");
	return 1;
}

if(SetInfo(&cur->data)) return 1;
cur->next=des->head;//��� �� ��� ���� �� ������
des->head=cur;//������ �������
return 0;
}



void freeList(struct stack *item) //������ ����
{
	if (item)
	{ 
		freeList(item->next); //���� � �����
		free(item); //���� ���� ����� �����
	}
}

void ClearAll(struct ListDescriptor *des)
{
	freeList(des->head); //pointer to stack top
}