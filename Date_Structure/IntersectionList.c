#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define OK 1
#define ERROF 0

typedef char ElemType;
typedef int Status;

typedef struct                                                           //����˳���
{
    ElemType *arr;
    int length;
}SqList;

Status InitList(SqList *L);                                              //������ʼ������
Status InputList(SqList *L);                                             //��������˳�����������
Status ComList(SqList *L1,SqList *L2,SqList *L3);                        //��������
Status OutputList(SqList *L);                                            //�����������


int main()                                                               //������
{
    SqList *L1,*L2,*L3,a,b,c;
    L1 = &a;
    L2 = &b;
    L3 = &c;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    printf("�������һ������Ԫ�أ�\n");
    InputList(L1);
    printf("������ڶ�������Ԫ�أ�\n");
    InputList(L2);
    ComList(L1,L2,L3);
    OutputList(L3);

}

Status InitList(SqList *L)                                               //��ʼ����������
{
    L->arr = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L->arr)
    {
        printf("Failed to initialize the order table!\n");
        return ERROF;
    }
    else
    {
        L->length = 0;
    printf("The order table was initialized Successfully!\n");
    return OK;
    }
}

Status InputList(SqList *L)                                                //˳�����������
{
    int i = 0,j,n;
    printf("������ ���� Ԫ�أ��س��������� $ Ϊ����:\n");
    printf("�뿪ʼ������루һ������һ����:  ");
    while(scanf("%s",&n)!=EOF)
        {
            L->arr[i] = n;
            while((L->arr[i]<'0' || L->arr[i]>'9') && L->arr[i]!='$')        //�����ж�
                {   
                    if(L->arr[i]>'0' && L->arr[i]<'9')  break;            
                    printf("������Ĳ������֣���������:  ");
                    scanf("%s",&(L->arr[i])); 
                                     
                }           
            for(j=0;j<i;j++)                                                 //�ظ��ж�
                {       
                    if(L->arr[i] == L->arr[j])
                        {
                            printf("�������ظ����������룺 ");
                            scanf("%s",&(L->arr[i]));
                        }                                              
                }
           if(L->arr[i]!='$')
               printf("����ɹ�����������һ����  ");                            //��ʾ�ɹ������������
            else  break;
            i++;  ++L->length;         
        }
        printf("���������\n"); 
    return OK;
}

Status ComList(SqList *L1,SqList *L2,SqList *L3)
{
    int i,j;
    for(i=0;i<L1->length;i++)
    {
        for(j=0;j<L2->length;j++)
        {
            if(L1->arr[i]==L2->arr[j])                                      //��ʼ�Ƚ���ͬ�Ĵ���L3��������
            {
                L3->arr[L3->length] = L1->arr[i];
                ++L3->length;
            }
        }
    }
}

Status OutputList (SqList *L)                                               //�������
{
    int k;
    printf("���ǵĽ���Ϊ�� L3 = { ");
    for(k=0;k<L->length;k++)
        printf("%c ",L->arr[k]);
    printf(" }");
    return OK;
}