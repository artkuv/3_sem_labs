///*В main используя указатель на указатель выделить память и ввесети матрицу целых чисел. В функции обнулить ВСЕ
//одинаковые числа стоящие под главной диагональю.*/
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <malloc.h>
//
////void func(int **mass, int n);
//
//void func(int **mas, int n)
//{
//	for (int i = 1; i < n; i++)
//	for (int j = 0; j < i; j++)
//	{
//		int tmp = mas[i][j];
//		for (int k = i + 1; k < n; k++)
//		{
//			for (int t = j; t < k; t++)
//			{
//				if (tmp == mas[k][t])
//				{
//					mas[i][j] = 0;
//					mas[k][t] = 0;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			printf("%d ", mas[i][j]);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n, i, j, s;
//	int **mas;
//
//	printf("vvedite razmernost");
//	do{
//		fflush(stdin);
//		s = scanf("%d", &n);
//	} while (s != 1 && n<2);
//
//	mas = (int**)malloc(sizeof(int*)*n);
//	if (!mas) return 0;
//	for (i = 0; i<n; i++)
//	{
//		mas[i] = (int*)malloc(sizeof(int)*n);
//		if (!mas[i]) return 0;
//	}
//	printf("\n");
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = 0; j<n; j++)
//		{
//			printf("enter value");
//			do{
//				fflush(stdin);
//				s = scanf("%d", &mas[i][j]);
//			} while (!s);
//		}
//	}
//
//	func(mas, n);
//
//	for (i = 0; i<n; i++)
//	{
//		free(mas[i]);
//	}
//	free(mas);
//
//	return 0;
//}
//
