#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define OK 1
#define EOF 0
static int count = 0;
int i;

Status InitList(LNode *L);
Status input(LNode *L);

typedef int Status;
typedef int ElemType;

typedef struct 
{
    ElemType id[N];
    ElemType data;
    ElemType next; 
}LNode;

Status main(void)
{    
    return EOF;
}

Status InitList(LNode *L)
{
     L = (ElemType*)malloca(sizeof(ElemType));
     L->next = NULL;
     return OK;
}
