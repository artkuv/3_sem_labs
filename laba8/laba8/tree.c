#include "list.h"
#include <string.h>

TREE* createTree(TREE *root)
{
	TREE *curTree, *subtree;
	char *eng, *rus;
	eng = (char*)malloc(MAX_LEN);
	rus = (char*)malloc(MAX_LEN);
	while (1)
	{
		puts("Enter english and russian meaning of the word:");
		gets(eng);
		if (!*eng)
		{
			free(eng);
			free(rus);
			if (!root)
				return 0;
			else
				return root;
		}
		gets(rus);
		if (!*rus)
		{
			free(rus);
			free(eng);
			if (!root)
				return 0;
			else
				return root;
		}
		curTree = (TREE*)malloc(sizeof(TREE));
		curTree->eng = (char*)malloc(strlen(eng) + 1);
		strcpy(curTree->eng, eng);
		curTree->rus = (char*)malloc(strlen(rus) + 1);
		strcpy(curTree->rus, rus);
		curTree->repeat = 1;
		curTree->left = curTree->right = NULL;
		if (!root)
		{
			root = curTree;
		}
		else
		{
			subtree = root;
			while (subtree)
			{
				if (!strcmp(curTree->eng, subtree->eng) && !strcmp(curTree->rus, subtree->rus))//если повторяется то не заполнять ее
				{
					subtree->repeat++;
					break;
					}
				else
				{
					if (strcmp(curTree->eng, subtree->eng)<0) //если меньше то заполняем в левую ветку, иначе в правую
					{
						if (!subtree->left)//если левой ветки нет,то заполняем ее curTree
						{
							subtree->left = curTree;
							subtree = curTree->left;
						}
						else//если левая ветка есть,то переходим на след уровень лев ветки
						{
							subtree = subtree->left;
						}
					}
					else
					{
						if (!subtree->right)//если левой ветки нет,то заполняем ее curTree
						{
							subtree->right = curTree;
							subtree = curTree->right;
						}
						else//если левая ветка есть,то переходим на след уровень лев ветки
						{
							subtree = subtree->right;
						}
					}
				}
			}
		}
	}
	free(eng);
	free(rus);
	return root;
}

TREE* createTreeRecursive(TREE *root, char* eng, char* rus)
{
	if (!root)
	{
		root = (TREE*)malloc(sizeof(TREE));
		root->eng = (char*)malloc(strlen(eng) + 1);
		strcpy(root->eng, eng);
		root->rus = (char*)malloc(strlen(rus) + 1);
		strcpy(root->rus, rus);
		root->repeat = 1;
		root->left = root->right = 0;
	}
	else
	{
		if (!strcmp(eng, root->eng) && !strcmp(rus, root->rus))
		{
			root->repeat++;
		}
		else
		{
			if (strcmp(eng, root->eng)<0)//если меньше то заполняем в левую ветку, иначе в правую
			{
				root->left = createTreeRecursive(root->left, eng, rus);
			}
			else
			{
				root->right = createTreeRecursive(root->right, eng, rus);
			}
		}
	}
	return root;
}

void showTreeRecursive(TREE *root)
{
	if (root)
	{
		printf("element contains: %s - %s, repeats:%d\n", root->eng, root->rus, root->repeat);
		if (root->left)
			showTreeRecursive(root->left);
		if (root->right)
			showTreeRecursive(root->right);
	}
}

void freeTreeRecursive(TREE *root)
{
	if (root)
	{
		if (root->left)
			freeTreeRecursive(root->left);
		if (root->right)
			freeTreeRecursive(root->right);
		free(root->eng);
		free(root->rus);
		free(root);
	}
}