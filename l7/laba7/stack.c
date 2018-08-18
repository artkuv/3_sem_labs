#include "list.h"

#define M 11
#define M1 50

void listInit(struct ListDescriptor *des)
{ des->head=NULL;
}

int AddItem(struct ListDescriptor *des)
{ struct stack *cur;
cur=(struct stack *)malloc(sizeof(struct stack));
if(!cur) {
	puts("ERROR");
	return 1;
}
if(SetInfo(&cur->data)) return 1;
cur->next=des->head;
des->head=cur;
return 0;
}

void ShowList(struct ListDescriptor *des)
{ int i=0;
struct stack *temp;
temp=des->head;
while(temp) {
	ShowInfo(&temp->data, i++);
	temp=temp->next;
}
}

int DeleteItem(struct ListDescriptor *des)
{ int num, flag; 
struct stack *temp, *r;
temp=des->head;
puts("kakoi elem udal?");
do {
	fflush(stdin);
	flag=scanf("%d", &num);
	if(num<0)
		flag=0;
} while(!flag);
if(!num) {
	des->head=des->head->next;
	free(temp);
}
else {
	for( ; num-1; num--) {
		temp=temp->next;
		if(!temp || !temp->next)
			return 1;
	}
	r=temp->next;
	temp->next=temp->next->next;
	free(r);
}
return 0;
}

int FindItem(struct ListDescriptor *des)
{ int flag=0, min;
char name[20];
struct stack *temp, *cur;
temp=des->head;
puts("vved naz igri\n");
fflush(stdin);
gets(name);
while(temp) {
	if(!strcmp(temp->data.name, name)) {
		if(flag==0) {
			flag=1;
			min=temp->data.cost;
			cur=temp;
		}
		if(temp->data.cost<min) {
			min=temp->data.cost;
			cur=temp;
		}
	}
	temp=temp->next;
}
if(!flag)
	return 1;
ShowInfo(&cur->data, -1);
return 0;
}

int in_file(struct ListDescriptor *des)
{ struct stack *temp;
char name[20];
FILE *f;
temp=des->head;
puts("imia faila?");
fflush(stdin);
gets(name);
if(!(f=fopen(name, "wb+")))
	return 1;
while(temp) {
	SaveInfoToFile(f, &temp->data);
	temp=temp->next;
}
fclose(f);
return 0;
}

int out_file(struct ListDescriptor *des)
{ FILE *f;
int flag;
char name[20];
struct stack *temp;
puts("imia faila?");
fflush(stdin);
gets(name);
if(!(f=fopen(name, "rb+"))) return 1;
ClearAll(des);
listInit(des);
while(1) {
temp=(struct stack *)malloc(sizeof(struct stack));
if(!temp) {
	puts("ERROR");
	return 1;
}
flag=readInfoFromFile(f, &temp->data);
if(flag==1)
	break;
if(flag==2)
	return 1;
temp->next=des->head;
des->head=temp;
}
return 0;
}

void freeList(struct stack *item) //recursive delete
{
	if (item) { //if an element exists
		freeList(item->next); //go deeper (to the stack bottom)
		free(item); //free elements from bottom to the top
	}
}

void ClearAll(struct ListDescriptor *des)
{
	freeList(des->head); //pointer to stack top
}