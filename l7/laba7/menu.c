#include "list.h"

#define M 11
#define M1 50

int main()
{ int flag, ans;
struct ListDescriptor head;
listInit(&head);
//Меню
do {
	puts("\n(1)dob elem\n(2)vivesti inf\n(3)udal elem\n(4)naiti elem\n(5)sohran fail\n(6)vzat iz faila\n(0)vihod\n");
	do {
	fflush(stdin);
	flag=scanf("%d", &ans);//ввод
	if(!flag || ans<0 || ans>6)
		puts("povt vvod");
} while(!flag);
	switch(ans)
	{	case 0: ClearAll(&head); return 0;//очистка и выход
		case 1: if(AddItem(&head)) return 0; break;//добавить
		case 2: ShowList(&head); break;//показ
		case 3: if(DeleteItem(&head)) puts("\nnet takogo elem\n"); break;//удал
		case 4: if(FindItem(&head)) puts("\nnet takogo elem\n"); break;//поиск
		case 5: if(in_file(&head)) puts("\noshibka s otkrit/sozd faila\n"); break;
		case 6: if(out_file(&head)) puts("\noshibka s otkrit/sozd faila\n"); break;
		default: return 0;
	}
	} while(1);
}