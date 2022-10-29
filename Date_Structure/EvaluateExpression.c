#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#define MAXSIZE 50
#define OK 1;
#define ERROR 0;

typedef int SElemType;
typedef int Status;
typedef char Elem;

typedef struct                          //建栈
{
    Elem *ST;
    SElemType base;
    SElemType top;
    SElemType stacksize;
}SqStack;

Status InitStack(SqStack *S);         //初始化声明
Status Push(SqStack *S,Elem e);       //入栈声明
Elem Pop(SqStack *S);                 //出栈声明
Status Input(SqStack *S);             //输入与操作声明

Status main()                          //主函数
{
    char l,k;
    SqStack a,*S;
    S = &a;
    InitStack(S);
    Input(S);
    free(S);
    return ERROR;
}

Status InitStack(SqStack *S)           //初始化定义
{
    S->ST = (Elem*)malloc(sizeof(Elem)*MAXSIZE);
    if(!S->ST)
    {
        printf("内存分配失败！\n");
        exit(0);
    }
    else
        printf("初始化成功！\n");
    S->base = S->top = 0;
    S->stacksize = MAXSIZE;
    return OK;
}

Status Push(SqStack *S,Elem e)          //入栈定义
{
    if(S->top == S->stacksize)
    {
		printf("栈满无法入栈！\n");
        return ERROR;
    }
    S->ST[S->top] = e;
    S->top++;
    return OK;
}

Elem Pop(SqStack *S)                    //出栈定义
{
    Elem u;
    if(S->base == S->top)
    {
        printf("栈空无法出栈！\n");
        return ERROR;
    }
   u = S->ST[--S->top];
   return u;
}

Status Input(SqStack *S)
{
    SElemType i,count = 0;
    Elem s,in[MAXSIZE];
    printf("请在英文输入法下输入表达式：\n\n");
    scanf("%s",in);
    for(i=0;i<strlen(in);i++)
    {
        if(in[i]=='(' || in[i]=='[' || in[i]=='{')
        {
             Push(S,in[i]);
             count++;
        }   
        if(in[i]==')' || in[i]==']' || in[i]=='}')
            count++;
        if((in[i]==')' || in[i]==']' || in[i]=='}') && (S->base == S->top))
        {
            printf("\n匹配结束！括号不匹配！\n\n");
            return ERROR;
        }
        else if(in[i]==')')
        {
            if ((s = Pop(S))!='(')
            {
                printf("\n匹配结束！括号不匹配！\n\n");
                return ERROR;
            }
        }
        else if(in[i]=='}')
        {
            if ((s = Pop(S))!='{')
            {
                printf("\n匹配结束！括号不匹配！\n\n");
                return ERROR;
            }
        }
        else if(in[i]== ']')
        {
            if (((s = Pop(S))!='['))
            {
                printf("\n匹配结束！括号不匹配！\n\n");
                return ERROR;
            }
        }
    }
    if(i==strlen(in) && S->top != 0)
    {
        printf("\n匹配结束！括号不匹配！\n\n");
        return ERROR;
    }
    if(count==0)
        printf("\n没有括号！\n\n");
    else
        printf("\n匹配结束！括号匹配呢！\n\n");
    return OK;
}