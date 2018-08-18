#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

typedef struct tree
{
	char *eng;
	char *rus;
	int repeat;
	struct tree *left;
	struct tree *right;
}TREE;

TREE *createTree(TREE*);
TREE *createTreeRecursive(TREE*, char*, char*);
void showTreeRecursive(TREE*);
void freeTreeRecursive(TREE *root);