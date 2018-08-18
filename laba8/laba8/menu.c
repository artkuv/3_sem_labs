#include "list.h"

int main()
{
	TREE *root = NULL;
	char *eng, *rus;
	while (1)
	{
		puts("Choose type of the operation:");
		puts("1. add elements (not recursive)");
		puts("2. add elements (recursive)");
		puts("3. recursive output");
		puts("4. exit");
		switch (getch())
		{
		case '1': root = createTree(root); break;
		case '2':
			eng = (char*)malloc(MAX_LEN);
			rus = (char*)malloc(MAX_LEN);
			while (1)
			{
				puts("Enter english and russian meaning of the word:");
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
		case '3': showTreeRecursive(root); break;
		case '4': freeTreeRecursive(root); return 0;
		}
	}
	return 0;
}