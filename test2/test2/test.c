#include <stdio.h>

int main(int argc, char *argv)
{
	int flag,i;

	puts("Enter 0 or 1");

	do
	{
		fflush(stdin);
		flag=scanf("%d", &i);

		//printf("flag=%d i=%d\n", flag, i);

		if(!flag || (flag && (i>1 || i<0)))
		{
			puts("Reenter number");
			flag=0;
		}
	}
	while(!flag);

	printf("%d \n", i);
	
	return 0;
}