#include <stdio.h>

int main()
{
        float a=0;
		float b=0;
		float c=0;
        printf("������� �����(�/�,��/�): ");
        scanf("%f %f",&a,&b);
        c=a*3.6;
        if (c>b)
         printf("%f �/� >%f ��/� \n",a,b);
        else if (c<b)
         printf("%f �/� <%f ��/� \n",a,b);
        else printf("%f �/� =%f ��/� \n",a,b);
return 0;
}
