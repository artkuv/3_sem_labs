#include "data.h"

#define M 11
#define M1 50

//���� ������
int SetInfo(struct info *ms)
{ int l, flag;
	printf("\nvved naz igri \n");//������� ������� ��������
	ms->name=(char *)malloc(20*sizeof(char));//����� ���
	if(!ms->name) {
		puts("ERROR");
		return 1;
	}
	fflush(stdin);
	gets(ms->name);//
	printf("\nvved stoim igri\n");//������� ����� �������
	do {
		fflush(stdin);
		flag=scanf("%d", &ms->cost);//��������
		if(!flag || ms->cost<=0)
			puts("povt vvod");
	} while(!flag);
	puts("\nvved janr igri (0) ili max kol igokov (1)?\n");//������ ���� ����������(0) ��� ������(1)
	do {
		fflush(stdin);
		flag=scanf("%d", &ms->id);//���� ��� ������
		if(!flag || ms->id!=0 && ms->id!=1)
			puts("povt vvod");
	} while(!flag);
	if(ms->id==0) {//���� 0 �� ����
		puts("\nvved janr igri\n");
		fflush(stdin);
		gets(ms->inf.genre);
	}
	else {// ���� 1 �� ��� �����
		puts("\nvved kol igokov\n");
		do {
			fflush(stdin);
			flag=scanf("%d", &ms->inf.maxpl);//vvod
			if(!flag || ms->inf.maxpl<0 || ms->inf.maxpl>100)
				puts("povt vvod");
		} while(!flag);
	}
	system("cls");//���� �������
	return 0;
} 
//����� ������
void ShowInfo(struct info *ms, int i)
{
	if(i>=0)
		printf("\nigra �%d\n", i);//����
	else printf("\n");
	printf("naz igri: %s\n", ms->name);//��� ����
	printf("stoim igri: %d\n", ms->cost);//����� ����
	if(ms->id==0) 
		printf("janr: %s\n", ms->inf.genre);//����
	else 
		printf("kol igrok: %d\n", ms->inf.maxpl);//��� �������
	
}
//����� ��� � ������������ ��� �������
void search_igra(struct info *ms, int *N)
{ int i, n;
for(i=0; i<*N; i++)
	if((ms+i)->id=='1') {
		n=(ms+i)->inf.maxpl;
		break;
	}
for(i++; i<*N; i++)
	if((ms+i)->id==1 && (ms+i)->inf.maxpl>n)
		n=(ms+i)->inf.maxpl;
puts("\n\nigra s max kol igrokov:\n\n");//���� � ���� ����
for(i=0; i<*N; i++)
	if((ms+i)->id==1 && (ms+i)->inf.maxpl==n)
		ShowInfo(ms, i);
}
//�������� �����������
void search_to_delete(struct info *ms, int *N)//���� �����
{ int i, j;
for(i=0; i<*N; i++)
	if((ms+i)->id==1) {
		(*N)--;
	for(j=i; j<*N; j++) {
		strcpy((ms+j)->name, (ms+(j+1))->name);
		(ms+j)->cost=(ms+(j+1))->cost;
		(ms+j)->id=(ms+(j+1))->id;
		strcpy((ms+j)->inf.genre, (ms+(j+1))->inf.genre);
		(ms+j)->inf.maxpl=(ms+(j+1))->inf.maxpl;
}
free((ms+*N)->name);
ms=(struct info *)realloc(ms, *N*sizeof(struct info));
i--;
	}
}

void SaveInfoToFile (FILE* f, struct info *data)//������ � ����
{ fwrite(data->name, 20*sizeof(char), 1, f);//��� ������ ���� � ����
fwrite(&data->cost, sizeof(int), 1, f);
fwrite(&data->id, sizeof(int), 1, f);
if(data->id==0)
	fwrite(&data->inf.genre, 11*sizeof(char), 1, f);
else 
	fwrite(&data->inf.maxpl, sizeof(int), 1, f);
}

int readInfoFromFile (FILE* f, struct info *data)//����� �� �����
{ data->name=(char *)malloc(20*sizeof(char));
if(!data->name)
	return 2;
if((fread(data->name, 20*sizeof(char), 1, f))!=1) {
	free(data->name);
	return 1;
}
if((fread(&data->cost, sizeof(int), 1, f))!=1) return 1;
if((fread(&data->id, sizeof(int), 1, f))!=1) return 1;
if(data->id==0) {
	if((fread(&data->inf.genre, 11*sizeof(char), 1, f))!=1) return 1;
}
else 
	if((fread(&data->inf.maxpl, sizeof(int), 1, f))!=1) return 1;
return 0;
}