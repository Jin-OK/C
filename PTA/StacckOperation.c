#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define EORROR 0

typedef int Status;
typedef int TElement;

typedef struct 
{
    TElement *base;
    TElement *top;
}Stack;

Status InitStack(Stack *T,TElement n);
Status Push(Stack *T,TElement m);
Status Pop(Stack *T);

Status main()
{
    TElement i,n,f,e;
    Stack a,*T;
    T = &a;
    scanf("%d",&n);
    InitStack(T,n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&f);
        if(f==1)
        {
            scanf("%d",&e);
            Push(T,e);
        }
        else
            Pop(T);
    }
    return 0;
}

Status InitStack(Stack *T,TElement n)
{
    T->base = (TElement*)malloc(sizeof(TElement)*n);
    T->top = T->base;
    return OK;
}

Status Push(Stack *T,TElement m)
{
    *T->top++ = m;
    return OK;
}

Status Pop(Stack *T)
{
    if(T->base==T->top)
        printf("invalid\n");
    else
    printf("%d\n",*--T->top);
    return OK;
}