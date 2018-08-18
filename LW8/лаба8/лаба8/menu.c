#include "list.h"

int main()
{
	TREE *root = NULL;
	char *eng, *rus;
	int level = 0;
	system("cls");
	while (1)
	{
		puts("Choose type of the operation:");
		puts("1. Create tree/add elements (Non recursive)");
		puts("2. Create tree/add elements (Recursive)");
		puts("3. Recursive output");
		puts("4. Non recursive output");
		puts("5. Delete element");
		puts("6. Exit");
		fflush(stdin);
		switch (getch())
		{
		case '1':
			root = createTree(root);
			break;
		case '2':
			eng = (char*)malloc(MAX_LEN);
			rus = (char*)malloc(MAX_LEN);
			while (1)
			{
				puts("Enter english and russian meaning of the word:\n");
				gets(eng);
				gets(rus);
				if (*eng && *rus)
					root = createTreeRecursive(root, eng, rus);
				else
					break;
			}
			free(eng);
			free(rus);
			break;
		case '3':
			showTreeRecursive(root);
			getch();
			break;
		case '4':
			showTreeUsingStack(root);
			getch();
			break;
		case '5':
			deleteNode(root);
			break;
		case '6':
			return 0;
		}
		system("cls");
	}
	return 0;
}