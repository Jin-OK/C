#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROF 0

typedef int ElemType;
typedef int Status;

typedef struct                                                           //定义顺序表
{
    ElemType *arr;
    ElemType length;
    ElemType j;                                                         //用来输出用
 }SqList;



Status InitList(SqList *L);                                              //初始化定义
Status LengthList(SqList *L);                                            //长度定义
Status InputList(SqList *L);                                             //输入定义
Status GetList(SqList *L);                                               //取值定义
Status LocateList(SqList *L);                                            //查找定义
Status InterList(SqList *L);                                             //插入定义
Status DeleteList(SqList *L);                                            //删除定义
Status ReplaceList(SqList *L);                                           //替换定义
Status ClearList(SqList *L);                                             //清除定义
Status OutList(SqList *L);                                               //输出定义



ElemType main()                                                          //主函数入口在这里！！！
{
    SqList *L,a;                                                          //顺序表指针变量
    L = &a;
    int n,i,t = 16;
    InitList(L);
    LengthList(L);
    InputList(L);
    printf("What do you want to do?\n");
    for(i=0;i<t;i++)                                                    //便于查看
    {
        printf("1-取值\t2-查找\n3-插入\t4-删除\n5-替换\t6-清除\n7-输出\t0-退出\n\t");
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
            default :printf("你会不会输入啊？重新输入:\n");break;      
        }
    }
    free(L->arr);
    return 0;
}




Status InitList(SqList *L)                                              //1、初始化操作函数
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

Status LengthList(SqList *L)                                               //2、顺序表的长度操作
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

Status InputList(SqList *L)                                                //3、顺序表的输入操作
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

Status GetList(SqList *L)                                                //4、顺序表的取值操作
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


Status LocateList(SqList *L)                                              //5、顺序表的查找操作
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


Status InterList(SqList *L)                                              //6、顺序表插入操作
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


Status DeleteList(SqList *L)                                            //7、顺序表的删除操作
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


Status ReplaceList(SqList *L)                                           //8、顺序表的替换操作
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


Status ClearList(SqList *L)                                              //9、顺序表的清除操作
{
    L->length = 0;
    L->j = 0;
     printf("Operate successfully!\n");
    return OK;
}


Status OutList(SqList *L)                                               //10、顺序表的输出
{
    int i;
    for(i=0;i<L->j;i++)
        printf("%4d",L->arr[i]);
        printf("\n");
        return OK;
}