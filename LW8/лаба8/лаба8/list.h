#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define MAX_LEN 20

typedef struct tree
{
	char *eng;
	char *rus;
	int repeat;
	struct tree *left;
	struct tree *right;
}TREE;

void showTreeRecursive(TREE*);
void showTreeUsingStack(TREE*);
TREE *createTree(TREE*);
TREE *createTreeRecursive(TREE*, char*, char*);
TREE *deleteNode(TREE*);
