#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define OK 1
#define ERROF 0

typedef int ElemType;
typedef int Status;

typedef struct                                                           //����˳���
{
    ElemType *arr;
    ElemType length;
}SqList;



Status InitList(SqList *L);                                              //��ʼ������
Status InpthList(SqList *L);                                             //���ȶ���
Status InputList(SqList *L);                                             //���붨��
Status GetList(SqList *L);                                               //ȡֵ����
Status LocateList(SqList *L);                                            //���Ҷ���
Status InterList(SqList *L);                                             //���붨��
Status DeleteList(SqList *L);                                            //ɾ������
Status ReplaceList(SqList *L);                                           //�滻����
Status ClearList(SqList *L);                                             //�������
Status OutList(SqList *L);                                               //�������



ElemType main()                                                          //������������������
{
    SqList *L,a;                                                         //˳���ָ�����
    L = &a;
    int n,i,t = 16;
    InitList(L);
    InputList(L);
    printf("What do you want to do?\n");
    for(i=0;i<t;i++)                                                 
    {
        printf("1-ȡֵ\t2-����\n3-����\t4-ɾ��\n5-�滻\t6-���\n7-���\t8-����\n\t0-�˳�\n\t");
        scanf("%d",&n);
        switch(n)
        {
            case 0:    free(L->arr);           return 0;
            case 1:GetList(L);    break;
            case 2:LocateList(L); break;
            case 3:InterList(L);  break;
            case 4:DeleteList(L); break;
            case 5:ReplaceList(L);break;
            case 6:ClearList(L);  break;
            case 7:OutList(L);    break;
            case 8:InpthList(L);  break;
            default :printf("��᲻�����밡����������:\n");break;      
        }
    }
    free(L->arr);
    return 0;
}




Status InitList(SqList *L)                                              //1����ʼ����������
{
    L->arr = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L->arr)
    {
        printf("Failed to initialize the order table!\n");
        return ERROF;
    }
    else
    {
    printf("The order table was initialized Successfully!\n");
    return OK;
    }
}

Status InpthList(SqList *L)                                               //2��˳���ĳ����������
{
    printf("The current length of the order table is : %d\n",L->length);
}

Status InputList(SqList *L)                                                //3��˳�����������
{
    int i,n;
    printf("How many do you want to enter:\n");
    scanf("%d",&n);
    if(n<=0 || n>=MAXSIZE)
        return ERROF;
    L->length = n;
    printf("Please enter it as follows:\n");
    for(i=0;i<n;i++)
         scanf("%d",&(L->arr[i]));
    printf("Operate Successfully!\n");
    return OK;
}

Status GetList(SqList *L)                                                //4��˳����ȡֵ����
{
    int m,k;
    printf("What do you want?\n");
    scanf("%d",&k);
    if(k<0 || k>=L->length)
        return ERROF;
    m = L->arr[k-1];
    printf("Here's what you get: %d\n",m);
    return OK;
}


Status LocateList(SqList *L)                                              //5��˳���Ĳ��Ҳ���
{
    int i,t;
    printf("Which one are you looking for?\n");
    scanf("%d",&t);
    for(i=0;i<L->length;i++)
    {
        if(t==L->arr[i])
        {
             printf("Here's what you get: arr[%d] = %d\n",i,t);
        }
        else if(i+1 == L->length)
        {
            printf("NO Found!\n");
            return OK;
        }
    }
}


Status InterList(SqList *L)                                              //6��˳���������
{
    int k,num,i;
    printf("Which do you want to insert after?\n");
    scanf("%d",&k);
    if(k<1 || k>=MAXSIZE)
    {
        printf("NO Operate!");
        return ERROF;
    }
     printf("What number do you want to insert ?\n");
     scanf("%d",&num);
     for(i=L->length;i>=k;i--)
        L->arr[i+1] = L->arr[i];
    L->arr[k] = num;
    ++L->length;
    printf("Operate Successfully!\n");
    return OK;
}


Status DeleteList(SqList *L)                                            //7��˳����ɾ������
{   
    int y,i,num;
    printf("Which one do you want to delete?\n");
    scanf("%d",&y);
    if(y<1 || y>L->length)
    {
        printf("NO Operate!");
        return ERROF;
    }
     for(i=y-1;i<L->length-1;i++)
        L->arr[i] = L->arr[i+1];
    --L->length;
    printf("Operate Successfully!\n");
    return OK;
}


Status ReplaceList(SqList *L)                                           //8��˳�����滻����
{
    int num,r;
    printf("Which one do you want to replace?\n");
    scanf("%d",&r);
    if(r<1 || r>L->length)
    {
        printf("NO Operate!");
        return ERROF;
    }
    printf("What number do you want to replace?\n");
    scanf("%d",&num);
    L->arr[r-1] = num;
     printf("Operate Successfully!\n");
    return OK;
}


Status ClearList(SqList *L)                                             //9��˳�����������
{
    L->length = 0;
     printf("Operate Successfully!\n");
    return OK;
}


Status OutList(SqList *L)                                               //10��˳�������
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%4d",L->arr[i]);
        printf("\n");
        return OK;
}