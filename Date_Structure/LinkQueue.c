#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define OK 1
#define EORROR 0

typedef int Status;
typedef char QElemType;

typedef struct  QNode           //定义链队
{
    QElemType data[MAXSIZE];
    struct QNode *next;         
}QNode,*QueuePtr;

typedef struct 
{
    QueuePtr front;             //队头指针
    QueuePtr rear;              //队尾指针
}LinkQueue;


Status InitQueue(LinkQueue *Q);   //初始化声明
Status EnQueue(LinkQueue *Q,QElemType *ch);     //入队声明
Status DeQueue(LinkQueue *Q,QElemType *e);        //出队声明
Status Judge(LinkQueue *Q);                 //判队空
QElemType GetQueue(LinkQueue *Q);   //查队

Status main()                               //主函数
{
    int i,k,n,decide;
    char name[MAXSIZE];
    LinkQueue a,b,*Q1,*Q2;
    Q1 = &a;
    Q2 = &b;
    InitQueue(Q1);
    InitQueue(Q2);
    printf("\t医院诊室候诊系统\n");
    printf("1-输入数据      2-显示排队\n3-开始就诊      4-退出系统\n");
    scanf("%d",&decide);
    for(k=0;k<16;k++)
    {
        switch (decide)
        {
            case 1: 
                    printf("输入以 # 为结束！\n");
                    while(name != "#")
                    {
                        printf("请输入名字： ");
                        gets(name);
                        EnQueue(Q1,name);
                        printf("存入成功！\n");
                    }      break;
            case 2:        break;
            case 3:        break;
            case 4:printf("退出系统！\n"); return 0;
            default:printf("输入错误，重新输入！\n");
                    scanf("%d",&decide);        break;
        }
    }
    return 0;
}

Status InitQueue(LinkQueue *Q)      //定义初始化
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->front->next = NULL;
    if(Q->front!=NULL)
    {
        printf("初始化完成！\n");
        return OK;
    }
    else
    {
        printf("初始化失败！\n");
        exit(EORROR);
    }

}

Status EnQueue(LinkQueue *Q,QElemType *ch)      //定义入队
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    strcpy(p->data,ch);                     //采用字符串复制方法存入
    p->next = NULL;
    Q->rear->next = p;                      //尾插法
    Q->rear = p;
    free(p);
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)       //定义出队
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        printf("队列为空，无法出队！\n");
        return EORROR;
    }
    p = Q->front->next;
    strcpy(e,p->data);
    Q->front->next = p->next;
    if(Q->rear==p)
        Q->rear = Q->front;
    free(p);
    return OK;
}

Status Judge(LinkQueue *Q)              //定义判空
{
    if(Q->front==Q->rear)
        return OK;
    else
        return 0;
}

QElemType GetQueue(LinkQueue *Q)        //定义查队
{
    int i;
    QueuePtr p;
    p = Q->front;
    while(p->next!=NULL)
    {
        p = p->next;
        return p->data;
    }
    return p->data;                     //返回最后一个元素
}