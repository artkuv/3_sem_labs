#include <stdio.h>
#include "list.h"

int main()
{
	struct ListDescriptor list;
	int i,flag;

	listInit(&list);

	while(1)
	{
		printf("what do you want:\n");
		printf("1. Add item\n");
		printf("2. Show list\n");
		printf("3. Delite item\n");
		printf("4. Find item\n");
		printf("5. Save to file\n");
		printf("6. Get from fie\n");
		printf("0. Exit\n");

		do
		{
			fflush(stdin);
			flag=scanf_s("%d", &i);

			//printf("flag=%d i=%d\n", flag, i);

			if(!flag || (flag && (i>6 || i<0)))
			{
				puts("Reenter number");
				flag=0;
			}
		}
		while(!flag);

		switch(i)
		{
		case 1: if(AddItem(&list)==0) puts("ok"); break;
		case 2: ShowList(&list); break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 0: ClearAll(&list); return 0;
		}
	}//while(1)
}