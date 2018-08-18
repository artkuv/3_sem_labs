#include "list.h"

#define M 11
#define M1 50

void listInit(struct ListDescriptor *des)
{ des->head=NULL;
des->tail=NULL;
}

int AddItem(struct ListDescriptor *des)
{ struct stack *temp;
temp=(struct stack *)malloc(sizeof(struct stack));
if(!temp) {
	puts("ERROR");
	return 1;
}
SetInfo(&temp->data);
if(!des->head) {
	des->head=temp;
	des->tail=temp;
	des->tail->next=NULL;
}
else {
	temp->next=des->tail->next;
	des->tail->next=temp;
	des->tail=temp;
}
return 0;
}

void ShowList(struct ListDescriptor *des)
{ int i=0;
struct stack *temp;
system("cls");
temp=des->head;
while(temp) {
	ShowInfo(&temp->data, i++);
	temp=temp->next;
}
}

int DeleteItem(struct ListDescriptor *des)
{ struct stack *temp, *r;
int num, flag;
puts("vved nomer udal elem \n");
do {
	fflush(stdin);
	flag=scanf("%d", &num);
	if(num<0)
		flag=0;
} while(!flag);
if(!des->head)
	return 1;
if(des->head==des->tail) {
	free(des->head);
	return 0;
}
if(num==0) {
	temp=des->head;
	des->head=des->head->next;
	free(temp);
	return 0;
}
temp=des->head;
while(num-1) {
	temp=temp->next;
	if(!temp)
		return 1;
}
if(!temp->next)
	return 1;
r=temp->next;
temp->next=r->next;
free(r);
return 0;
}

int FindItem(struct ListDescriptor *des)
{ int flag=0, max;
char name[20];
struct stack *temp, *cur;
temp=des->head;
puts("vved naz igri\n");//vved famil stud
fflush(stdin);
gets(name);
while(temp) {
	if(!strcmp(temp->data.name, name)) {
		if(flag==0) {
			flag=1;
			max=temp->data.cost;
			cur=temp;
		}
		if(temp->data.cost>max) {
			max=temp->data.cost;
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
int flag, f1=1;
char name[20];
struct stack *temp, *r;
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
if(f1) {
	temp->next=des->tail;
	des->head=temp;
	des->tail=temp;
	f1=0;
	continue;
}
temp->next=des->tail->next;
des->tail->next=temp;
des->tail=temp;
}
return 0;
}

void ClearAll(struct ListDescriptor *des)
{
	struct stack *temp=des->head;
	while(des->head!=des->tail)
	{
		des->head=des->head->next;
		free(temp);
		temp=des->head;
	}
	if(des->tail) free(des->tail);
}