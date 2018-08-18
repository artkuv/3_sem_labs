#include "data.h"

#define M 11
#define M1 50

#ifdef LIST_RING
typedef struct stack
{ struct info data;
struct stack *next;
struct stack *prev;
};
#else
typedef struct stack
{ struct info data;
struct stack *next;
};
#endif

#ifdef LIST_QUEUE
typedef struct ListDescriptor
{ struct stack *head;
struct stack *tail;
};
#else
typedef struct ListDescriptor
{ struct stack *head;
};
#endif

void listInit(struct ListDescriptor *);

int AddItem(struct ListDescriptor *);
void ShowList(struct ListDescriptor *);
int DeleteItem(struct ListDescriptor *);
void freeList(struct stack *);
void ClearAll(struct ListDescriptor *);
int FindItem(struct ListDescriptor *);
int in_file(struct ListDescriptor *);
int out_file(struct ListDescriptor *);