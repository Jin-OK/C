#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define OK 1
#define ERROF 0

typedef char ElemType;
typedef int Status;

typedef struct                                                           //定义顺序表
{
    ElemType *arr;
    int length;
}SqList;

Status InitList(SqList *L);                                              //声明初始化定义
Status InputList(SqList *L);                                             //声明集合顺序表的输入操作
Status ComList(SqList *L1,SqList *L2,SqList *L3);                        //声明交集
Status OutputList(SqList *L);                                            //声明输出交集


int main()                                                               //主函数
{
    SqList *L1,*L2,*L3,a,b,c;
    L1 = &a;
    L2 = &b;
    L3 = &c;
    InitList(L1);
    InitList(L2);
    InitList(L3);
    printf("请输入第一个集合元素；\n");
    InputList(L1);
    printf("请输入第二个集合元素；\n");
    InputList(L2);
    ComList(L1,L2,L3);
    OutputList(L3);

}

Status InitList(SqList *L)                                               //初始化操作函数
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

Status InputList(SqList *L)                                                //顺序表的输入操作
{
    int i = 0,j,n;
    printf("请输入 数字 元素，回车继续，以 $ 为结束:\n");
    printf("请开始你的输入（一次输入一个）:  ");
    while(scanf("%s",&n)!=EOF)
        {
            L->arr[i] = n;
            while((L->arr[i]<'0' || L->arr[i]>'9') && L->arr[i]!='$')        //错误判断
                {   
                    if(L->arr[i]>'0' && L->arr[i]<'9')  break;            
                    printf("你输入的不是数字，重新输入:  ");
                    scanf("%s",&(L->arr[i])); 
                                     
                }           
            for(j=0;j<i;j++)                                                 //重复判断
                {       
                    if(L->arr[i] == L->arr[j])
                        {
                            printf("你输入重复，重新输入： ");
                            scanf("%s",&(L->arr[i]));
                        }                                              
                }
           if(L->arr[i]!='$')
               printf("输入成功，请输入下一个：  ");                            //提示成功存入继续输入
            else  break;
            i++;  ++L->length;         
        }
        printf("输入结束！\n"); 
    return OK;
}

Status ComList(SqList *L1,SqList *L2,SqList *L3)
{
    int i,j;
    for(i=0;i<L1->length;i++)
    {
        for(j=0;j<L2->length;j++)
        {
            if(L1->arr[i]==L2->arr[j])                                      //开始比较相同的存入L3（交集）
            {
                L3->arr[L3->length] = L1->arr[i];
                ++L3->length;
            }
        }
    }
}

Status OutputList (SqList *L)                                               //输出函数
{
    int k;
    printf("它们的交集为： L3 = { ");
    for(k=0;k<L->length;k++)
        printf("%c ",L->arr[k]);
    printf(" }");
    return OK;
}