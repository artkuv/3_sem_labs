#include "list.h"

void listInit(struct ListDescriptor *des)
{ des->head=NULL;//��������� ������
}

int AddItem(struct ListDescriptor *des)
{ struct stack *temp;
temp=(struct stack *)malloc(sizeof(struct stack));//����� ���
if(!temp) {//��������
	puts("ERROR");
	return 1;
}
if(SetInfo(&temp->data)) return 1;//����� �����
if(!des->head) {//���� ������ 
	des->head=temp;//����� ��� �� ������
	des->head->next=des->head->prev=des->head;//��� ����� �� ���
}
else {//���� ���� ���� �� �����
	temp->next=des->head;//���� �� ���� ����
	temp->prev=des->head->prev;//���� �� ������
	temp->prev->next=temp;//���� ���� �� ����
	des->head->prev=temp;//������ �� ����
}
return 0;
}

void ShowList(struct ListDescriptor *des)//�����
{ int i=0, ans, flag;
struct stack *temp;
if(!des->head) puts("\nERROR\n");//���� ��� ������
else {
	puts("\nvivesti inf s golovi(0) ili hvosta(1)\n");//������� ���������� ������� � ������(0) ��� � ������(1)
	do {
		fflush(stdin);
		flag=scanf("%d", &ans);//����
		if(ans!=0 && ans!=1)
			flag=0;
	} while(!flag);
	system("cls");
	if(ans) {
		temp=des->head->prev;//� ������
		do {
			ShowInfo(&temp->data, i++);//�����
			temp=temp->prev;//���� �� ������
		} while(temp!=des->head->prev);
	}
	else {//� �� ��������
		temp=des->head;
		do {
			ShowInfo(&temp->data, i++);
			temp=temp->next;
		} while(temp!=des->head);
	}
}
}

int DeleteItem(struct ListDescriptor *des)
{ struct stack *temp, *r;
int num, flag;
puts("vved nomer udal elem \n");//������� ����� ���������� ��������
do {
	fflush(stdin);
	flag=scanf("%d", &num);
	if(num<0)
		flag=0;
} while(!flag);
if(!des->head)
	return 1;
if(des->head==des->head->prev) {
	free(des->head);
	return 0;
}
temp=des->head;
while(num--) temp=temp->next;
if(temp==des->head) {
	des->head=des->head->next;
	des->head->prev=temp->prev;
	temp->prev->next=des->head;
	free(temp);
}
else
	if(temp==des->head->prev) {
		temp->prev->next=des->head;
		des->head->prev=temp->prev;
		free(temp);
	}
	else {
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
return 0;
}

int FindItem(struct ListDescriptor *des)
{ int flag=0;
char name[20];
struct stack *temp;
temp=des->head;
puts("vved naz igri\n");
fflush(stdin);
gets(name);
system("cls");
do {
	if(!strcmp(temp->data.name, name)) {
		if(flag==0)
			flag=1;
		ShowInfo(&temp->data, -1);
	}
	temp=temp->next;
} while(temp!=des->head);
if(!flag)
	return 1;
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
do {
	SaveInfoToFile(f, &temp->data);
	temp=temp->next;
} while(temp!=des->head);
fclose(f);
return 0;
}

int out_file(struct ListDescriptor *des)//����� �� �����
{ FILE *f;
int flag;
char name[20];
struct stack *temp, *r;
puts("imia faila?");
fflush(stdin);
gets(name);
if(!(f=fopen(name, "rb+"))) return 1;
ClearAll(des);
listInit(des);
while(1) {
temp=(struct stack *)malloc(sizeof(struct stack));//������
if(!temp) {
	puts("ERROR");
	return 1;
}
flag=readInfoFromFile(f, &temp->data);//���� ������
if(flag==1) {
	free(temp);
	break;
}
if(flag==2) {
	free(temp);
	return 1;
}
if(!des->head) {
	des->head=temp;
	des->head->next=des->head->prev=des->head;
	continue;
}
temp->next=des->head;
temp->prev=des->head->prev;
temp->prev->next=temp;
des->head->prev=temp;
}
return 0;
}

void ClearAll(struct ListDescriptor *des)//������
{ struct Item *tail;
	if(des->head) {
		tail=des->head->prev;
		while(des->head!=tail) {
			des->head=des->head->next;
			free(des->head->prev);
		}
	free(tail);
}
}