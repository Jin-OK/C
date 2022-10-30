#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define MOREPOPLE 100
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
Status GetQueue(LinkQueue *Q);   //查队


Status main()                               //主函数
{
   int k,i,n = 0,decide1,decide2;
    char name[MAXSIZE];
    LinkQueue a,b,*Q1,*Q2;
    Q1 = &a;
    Q2 = &b;
    InitQueue(Q1);
    InitQueue(Q2);
    printf("\t医院诊室候诊系统\n");
    for(k=0;k<16;k++)
    {
    De1:
        printf("1-输入数据      2-显示排队\n3-开始就诊      4-退出系统\n");
        scanf("%d",&decide1);
        switch (decide1)
        {
            case 1:
                for(i=0;i<MOREPOPLE;i++)
                {
                    printf("请选择输入类型：1-普通诊\t2-急诊 \t  3-退出输入\n");
                    scanf("%d",&decide2);
                    switch(decide2)
                    {
                        case 1:
                        printf("输入以 # 为结束！\n");
                        while(1)
                         {
                            printf("请输入名字： ");
                            scanf("%s",name);
                            name[strlen(name)] = '\0';
                            if(strcmp("#",name)!=0)
                            {
                                EnQueue(Q1,name);
                                printf("存入成功！\n");
                            }
                            else break;
                           
                        }      break;
                        case 2:
                        printf("输入以 # 为结束！\n");
                        while(1)
                         {
                            printf("请输入名字： ");
                            scanf("%s",name);
                            name[strlen(name)] = '\0';
                            if(strcmp("#",name)!=0)
                            {
                                EnQueue(Q2,name);
                                printf("存入成功！\n");
                            }
                            else break;
                           
                        }      break;
                        case 3:
                        printf("退出输入！\n");
                        goto De1;
                        default:
                        printf("输入错误，重新输入！\n");
                            break;
                    } 
                }             
            case 2:
             if(Judge(Q2)==0)
                        printf("急诊没有人排队！\n");
                    else
                    {
                        printf("急诊有以下人排队：\n");
                        n = GetQueue(Q2);
                        printf("\n共 %d 人！\n",n);
                    } 
                n = 0;
            if(Judge(Q1)==0)
                        printf("\n普通诊没有人排队！\n\n");
                    else
                    {
                        printf("\n普通诊有以下人排队：\n\n");
                        n = GetQueue(Q1);
                        printf("\n共 %d 人！\n\n",n);
                    }      break;
            case 3: if(Judge(Q2)!=0)
                    {
                        DeQueue(Q2,name);
                        printf("现在是急诊的出队,名字是： %s\n\n",name);
                        continue;
                    }
                    if(Judge(Q2)==0 && Judge(Q1)!=0)
                    {
                        
                        DeQueue(Q1,name);
                        printf("现在是普通诊的出队,名字是： %s\n\n",name);continue;
                    }
                    if(Judge(Q1)==Judge(Q2) && Judge(Q2)==0)
                        printf("已经没有人了！\n\n");
                   break;
            case 4:printf("退出系统！\n");
                    free(Q1);free(Q2);
                     return 0;
            default:printf("输入错误，重新输入！\n");
                          break;
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
        return 0;
    else
        return OK;
}

Status GetQueue(LinkQueue *Q)           //定义查队
{
    int i = 0;
    QNode* p;
    p = Q->front;
   while(p->next!=NULL)
    {
        i++;
        p = p->next;
        puts(p->data);
    }
    return i;
}