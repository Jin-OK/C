#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROF 0

typedef int ElemType;
typedef int Status;

typedef struct                                                           //����˳���
{
    ElemType *arr;
    ElemType length;
    ElemType j;                                                         //���������
 }SqList;



Status InitList(SqList *L);                                              //��ʼ������
Status LengthList(SqList *L);                                            //���ȶ���
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
    SqList *L,a;                                                          //˳���ָ�����
    L = &a;
    int n,i,t = 16;
    InitList(L);
    LengthList(L);
    InputList(L);
    printf("What do you want to do?\n");
    for(i=0;i<t;i++)                                                    //���ڲ鿴
    {
        printf("1-ȡֵ\t2-����\n3-����\t4-ɾ��\n5-�滻\t6-���\n7-���\t0-�˳�\n\t");
        scanf("%d",&n);
        switch(n)
        {
            case 0:               return 0;
            case 1:GetList(L);    break;
            case 2:LocateList(L); break;
            case 3:InterList(L);  break;
            case 4:DeleteList(L); break;
            case 5:ReplaceList(L);break;
            case 6:ClearList(L);  break;
            case 7:OutList(L);    break;
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
    printf("The order table was initialized successfully!\n");
    return OK;
    }
}

Status LengthList(SqList *L)                                               //2��˳���ĳ��Ȳ���
{
    int n;
    printf("How many elements do you want to enter?\n");
    scanf("%d",&n);
    if(n<=0 || n>MAXSIZE)
         return ERROF;
    else
    {
        L->length = n;
        printf("Operate successfully!\n");
        return OK;
    }
}

Status InputList(SqList *L)                                                //3��˳�����������
{
    int i,n;
    printf("How many do you want to enter:\n");
    scanf("%d",&n);
    if(n<0 || n>=L->length)
        return ERROF;
    L->j = n;
    printf("Please enter it as follows:\n");
    for(i=0;i<n;i++)
         scanf("%d",&(L->arr[i]));
    printf("Operate successfully!\n");
    return OK;
}

Status GetList(SqList *L)                                                //4��˳����ȡֵ����
{
    int m,k;
    printf("What do you want?\n");
    scanf("%d",&k);
    if(k<0 || k>=L->j)
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
    for(i=0;i<L->j;i++)
    {
        if(t==L->arr[i])
        {
             printf("Here's what you get: arr[%d] = %d\n",i,t);
        }
        else if(i+1 == L->j)
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
    if(k<1 || k>=L->length-1)
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
    ++L->j;
    printf("Operate successfully!\n");
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
    --L->j;
    printf("Operate successfully!\n");
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
     printf("Operate successfully!\n");
    return OK;
}


Status ClearList(SqList *L)                                              //9��˳�����������
{
    L->length = 0;
    L->j = 0;
     printf("Operate successfully!\n");
    return OK;
}


Status OutList(SqList *L)                                               //10��˳�������
{
    int i;
    for(i=0;i<L->j;i++)
        printf("%4d",L->arr[i]);
        printf("\n");
        return OK;
}