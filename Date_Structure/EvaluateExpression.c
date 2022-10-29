#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#define MAXSIZE 50
#define OK 1;
#define ERROR 0;

typedef int SElemType;
typedef int Status;
typedef char Elem;

typedef struct                          //��ջ
{
    Elem *ST;
    SElemType base;
    SElemType top;
    SElemType stacksize;
}SqStack;

Status InitStack(SqStack *S);         //��ʼ������
Status Push(SqStack *S,Elem e);       //��ջ����
Elem Pop(SqStack *S);                 //��ջ����
Status Input(SqStack *S);             //�������������

Status main()                          //������
{
    char l,k;
    SqStack a,*S;
    S = &a;
    InitStack(S);
    Input(S);
    free(S);
    return ERROR;
}

Status InitStack(SqStack *S)           //��ʼ������
{
    S->ST = (Elem*)malloc(sizeof(Elem)*MAXSIZE);
    if(!S->ST)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(0);
    }
    else
        printf("��ʼ���ɹ���\n");
    S->base = S->top = 0;
    S->stacksize = MAXSIZE;
    return OK;
}

Status Push(SqStack *S,Elem e)          //��ջ����
{
    if(S->top == S->stacksize)
    {
		printf("ջ���޷���ջ��\n");
        return ERROR;
    }
    S->ST[S->top] = e;
    S->top++;
    return OK;
}

Elem Pop(SqStack *S)                    //��ջ����
{
    Elem u;
    if(S->base == S->top)
    {
        printf("ջ���޷���ջ��\n");
        return ERROR;
    }
   u = S->ST[--S->top];
   return u;
}

Status Input(SqStack *S)
{
    SElemType i,count = 0;
    Elem s,in[MAXSIZE];
    printf("����Ӣ�����뷨��������ʽ��\n\n");
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
            printf("\nƥ����������Ų�ƥ�䣡\n\n");
            return ERROR;
        }
        else if(in[i]==')')
        {
            if ((s = Pop(S))!='(')
            {
                printf("\nƥ����������Ų�ƥ�䣡\n\n");
                return ERROR;
            }
        }
        else if(in[i]=='}')
        {
            if ((s = Pop(S))!='{')
            {
                printf("\nƥ����������Ų�ƥ�䣡\n\n");
                return ERROR;
            }
        }
        else if(in[i]== ']')
        {
            if (((s = Pop(S))!='['))
            {
                printf("\nƥ����������Ų�ƥ�䣡\n\n");
                return ERROR;
            }
        }
    }
    if(i==strlen(in) && S->top != 0)
    {
        printf("\nƥ����������Ų�ƥ�䣡\n\n");
        return ERROR;
    }
    if(count==0)
        printf("\nû�����ţ�\n\n");
    else
        printf("\nƥ�����������ƥ���أ�\n\n");
    return OK;
}