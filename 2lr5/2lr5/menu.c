#include "list.h"

#define M 11
#define M1 50

int main()
{ int flag, ans;
struct ListDescriptor head;
listInit(&head);
//Меню
do {
	puts("\nmenu:");
	puts("(1)dob elem");
	puts("(0)vihod");
	do {
	fflush(stdin);
	flag=scanf("%d", &ans);//ввод
	if(!flag || ans<0 || ans>1)
		puts("povt vvod");
} while(!flag);
  switch(ans)
	 {	
		case 1: if(AddItem(&head)) return 0; break;//добавить
		case 0: ClearAll(&head); return 0;//очистка и выход
		default: return 0;
	 }
	} while(1);
}