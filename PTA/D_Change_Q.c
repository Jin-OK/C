#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 1
#define MAXSIZE 100   // MAXSIZE为最大数据元素数目

typedef int ElemType;
typedef int Status;

typedef struct
{   ElemType  *base;
    ElemType  *top;
}SqStack;

Status InitStack(SqStack *S);     
Status Push(SqStack *S,ElemType e);  
Status Pop(SqStack *S);  
Status Change(SqStack *S,ElemType n);

Status main()
{
    ElemType n;
    SqStack a,*S;
    S = &a;
    InitStack(S);
    scanf("%d",&n);
    Change(S,n);
    return 0;
}

Status InitStack(SqStack *S)
{
    S->base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    S->top = S->base;
    return OK;
}

Status Push(SqStack *S,ElemType e)
{
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S)
{
    int d;
    d = *--S->top;
    return d;
}

Status Change(SqStack *S,ElemType n)
{
    ElemType count,num,i,Fn,m;
    while(1)
    {
        num = n%8;
        Push(S,num);
        count++;
        n /= 8;
         if(n==0)
            break;
    }
    for(i=count-1;i>=0;i--)
    {
        num = Pop(S);
        printf("%d",num);
    }
    return OK;
}