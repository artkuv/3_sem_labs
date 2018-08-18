#include "list.h"

TREE* createTree(TREE *root)
{
	TREE *curTree, *subtree;
	char *eng, *rus;
	eng = (char*)malloc(MAX_LEN);
	rus = (char*)malloc(MAX_LEN);
	while (1)
	{
		puts("Enter english and russian meaning of the word:\n");
		gets(eng);
		if (!*eng)
		{
			free(eng);
			if (!root)
				return NULL;
			else
				return root;
		}
		gets(rus);
		if (!*rus)
		{
			free(rus);
			free(eng);
			if (!root)
				return NULL;
			else
				return root;
		}
		curTree = (TREE*)malloc(sizeof(TREE));
		curTree->eng = (char*)malloc(strlen(eng) + 1);
		strcpy(curTree->eng, eng);
		curTree->rus = (char*)malloc(strlen(rus) + 1);
		strcpy(curTree->rus, rus);
		curTree->repeat = 1;
		curTree->left = curTree->right = 0;
		if (!root)
		{
			root = curTree;
		}
		else
		{
			subtree = root;
			while (subtree)
			{
				if (!strcmp(curTree->eng, subtree->eng) && !strcmp(curTree->rus, subtree->rus))
				{
					subtree->repeat++;
					break;
				}
				else
				{
					if (strcmp(curTree->eng, subtree->eng)<0)
					{
						if (!subtree->left)
						{
							subtree->left = curTree;
							subtree = curTree->left;
						}
						else
						{
							subtree = subtree->left;
						}
					}
					else
					{
						if (!subtree->right)
						{
							subtree->right = curTree;
							subtree = curTree->right;
						}
						else
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
			if (strcmp(eng, root->eng)<0)
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
		printf("Knot contains: %s - %s, number of meetings:%d\n", root->eng, root->rus, root->repeat);
		if (root->left)
			showTreeRecursive(root->left);
		if (root->right)
			showTreeRecursive(root->right);
	}
}

void showTreeUsingStack(TREE *root)
{
	struct stack
	{
		TREE *tree;
		struct stack *next;
	}*stackElement, *stackPointer = NULL;
	int flag = 1;
	if (!root)
	{
		printf("Tree is empty");
		return;
	}
	stackElement = (struct stack*)calloc(1, sizeof(struct stack));
	stackElement->tree = root;
	stackElement->next = stackPointer;
	printf("Node contains: %s - %s, number of meetings:%d\n", root->eng, root->rus, root->repeat);
	while (stackElement || root->right)
	{
		do
		{
			if (flag && root->left)
				root = root->left;
			else
			{
				if (root->right)
					root = root->right;
			}
			flag = 1;
			if (root->left && root->right)
			{
				stackPointer = stackElement;
				stackElement = (struct stack*)calloc(1, sizeof(struct stack));
				stackElement->tree = root;
				stackElement->next = stackPointer;
			}
			printf("Knot contains: %s - %s, number of meetings:%d\n", root->eng, root->rus, root->repeat);
		} while (root->left || root->right);
		if (stackElement)
		{
			root = stackElement->tree;
			stackPointer = stackElement->next;
			free(stackElement);
		}
		stackElement = stackPointer;
		if (root->right)
			flag = 0;
	}
}

TREE* deleteNode(TREE *root)
{
	TREE *parentNode, *tempNode, *curNode;
	char *eng, *rus;
	int comparing1, comparing2;
	int flag;
	if (!root)
	{
		puts("Tree is empty");
		return NULL;
	}
	puts("Whitch words you would like to delete: ");
	eng = (char*)malloc(MAX_LEN * sizeof(char));
	fflush(stdin);
	gets(eng);
	if (!eng)
		return NULL;
	rus = (char*)malloc(MAX_LEN * sizeof(char));
	fflush(stdin);
	gets(rus);
	if (!rus)
		return NULL;
	curNode = parentNode = root;
	flag = 0;
	do
	{
		if (!(comparing1 = strcmp(eng, parentNode->eng)) && !(comparing2 = strcmp(rus, parentNode->rus)))
			flag = 1;
		if (comparing1<0)
		{
			if (parentNode->left)
			{
				curNode = parentNode;
				parentNode = parentNode->left;
			}
			else
				flag = 1;
		}
		if (comparing1>0)
		{
			if (parentNode->right)
			{
				curNode = parentNode;
				parentNode = parentNode->right;
			}
			else
				flag = 1;
		}
	} while (!flag);
	free(eng);
	free(rus);
	if (comparing1 && comparing2)
	{
		puts("No such node\n");
		getch();
		return root;
	}
	else
	{
		comparing1 = strcmp(parentNode->eng, curNode->eng);
		tempNode = parentNode;
		if (comparing1 < 0)
		{
			tempNode = parentNode->right;
			if (!tempNode)
				curNode->left = NULL;
			else
			{
				while (tempNode->left)
					tempNode = tempNode->left;
				curNode->left = parentNode->right;
				tempNode->left = parentNode->left;
			}
		}
		else if (comparing1 > 0)
		{
			tempNode = parentNode->left;
			if (!tempNode)
				curNode->right = NULL;
			else
			{
				while (tempNode->right)
					tempNode = tempNode->right;
				curNode->right = parentNode->left;
				tempNode->right = parentNode->right;
			}
		}
		else
		{
			printf("You can't delete the root!");
			getch();
		}
	}
}