#include "data.h"

#define M 11
#define M1 50


typedef struct stack
{ struct info data;
struct stack *next;
};

typedef struct ListDescriptor
{ struct stack *head;
};


void listInit(struct ListDescriptor *);
int AddItem(struct ListDescriptor *);
void freeList(struct stack *);
void ClearAll(struct ListDescriptor *);//выход с очищ
