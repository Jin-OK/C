#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define OK 1
#define EORROR 0

typedef int Status;
typedef char QElemType;

typedef struct  QNode           //��������
{
    QElemType data[MAXSIZE];
    struct QNode *next;         
}QNode,*QueuePtr;

typedef struct 
{
    QueuePtr front;             //��ͷָ��
    QueuePtr rear;              //��βָ��
}LinkQueue;


Status InitQueue(LinkQueue *Q);   //��ʼ������
Status EnQueue(LinkQueue *Q,QElemType *ch);     //�������
Status DeQueue(LinkQueue *Q,QElemType *e);        //��������
Status Judge(LinkQueue *Q);                 //�жӿ�
QElemType GetQueue(LinkQueue *Q);   //���

Status main()                               //������
{
    int i,k,n,decide;
    char name[MAXSIZE];
    LinkQueue a,b,*Q1,*Q2;
    Q1 = &a;
    Q2 = &b;
    InitQueue(Q1);
    InitQueue(Q2);
    printf("\tҽԺ���Һ���ϵͳ\n");
    printf("1-��������      2-��ʾ�Ŷ�\n3-��ʼ����      4-�˳�ϵͳ\n");
    scanf("%d",&decide);
    for(k=0;k<16;k++)
    {
        switch (decide)
        {
            case 1: 
                    printf("������ # Ϊ������\n");
                    while(name != "#")
                    {
                        printf("���������֣� ");
                        gets(name);
                        EnQueue(Q1,name);
                        printf("����ɹ���\n");
                    }      break;
            case 2:        break;
            case 3:        break;
            case 4:printf("�˳�ϵͳ��\n"); return 0;
            default:printf("��������������룡\n");
                    scanf("%d",&decide);        break;
        }
    }
    return 0;
}

Status InitQueue(LinkQueue *Q)      //�����ʼ��
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->front->next = NULL;
    if(Q->front!=NULL)
    {
        printf("��ʼ����ɣ�\n");
        return OK;
    }
    else
    {
        printf("��ʼ��ʧ�ܣ�\n");
        exit(EORROR);
    }

}

Status EnQueue(LinkQueue *Q,QElemType *ch)      //�������
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    strcpy(p->data,ch);                     //�����ַ������Ʒ�������
    p->next = NULL;
    Q->rear->next = p;                      //β�巨
    Q->rear = p;
    free(p);
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)       //�������
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        printf("����Ϊ�գ��޷����ӣ�\n");
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

Status Judge(LinkQueue *Q)              //�����п�
{
    if(Q->front==Q->rear)
        return OK;
    else
        return 0;
}

QElemType GetQueue(LinkQueue *Q)        //������
{
    int i;
    QueuePtr p;
    p = Q->front;
    while(p->next!=NULL)
    {
        p = p->next;
        return p->data;
    }
    return p->data;                     //�������һ��Ԫ��
}