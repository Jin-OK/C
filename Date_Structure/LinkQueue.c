#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
#define MOREPOPLE 100
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
Status GetQueue(LinkQueue *Q);   //���


Status main()                               //������
{
   int k,i,n = 0,decide1,decide2;
    char name[MAXSIZE];
    LinkQueue a,b,*Q1,*Q2;
    Q1 = &a;
    Q2 = &b;
    InitQueue(Q1);
    InitQueue(Q2);
    printf("\tҽԺ���Һ���ϵͳ\n");
    for(k=0;k<16;k++)
    {
    De1:
        printf("1-��������      2-��ʾ�Ŷ�\n3-��ʼ����      4-�˳�ϵͳ\n");
        scanf("%d",&decide1);
        switch (decide1)
        {
            case 1:
                for(i=0;i<MOREPOPLE;i++)
                {
                    printf("��ѡ���������ͣ�1-��ͨ��\t2-���� \t  3-�˳�����\n");
                    scanf("%d",&decide2);
                    switch(decide2)
                    {
                        case 1:
                        printf("������ # Ϊ������\n");
                        while(1)
                         {
                            printf("���������֣� ");
                            scanf("%s",name);
                            name[strlen(name)] = '\0';
                            if(strcmp("#",name)!=0)
                            {
                                EnQueue(Q1,name);
                                printf("����ɹ���\n");
                            }
                            else break;
                           
                        }      break;
                        case 2:
                        printf("������ # Ϊ������\n");
                        while(1)
                         {
                            printf("���������֣� ");
                            scanf("%s",name);
                            name[strlen(name)] = '\0';
                            if(strcmp("#",name)!=0)
                            {
                                EnQueue(Q2,name);
                                printf("����ɹ���\n");
                            }
                            else break;
                           
                        }      break;
                        case 3:
                        printf("�˳����룡\n");
                        goto De1;
                        default:
                        printf("��������������룡\n");
                            break;
                    } 
                }             
            case 2:
             if(Judge(Q2)==0)
                        printf("����û�����Ŷӣ�\n");
                    else
                    {
                        printf("�������������Ŷӣ�\n");
                        n = GetQueue(Q2);
                        printf("\n�� %d �ˣ�\n",n);
                    } 
                n = 0;
            if(Judge(Q1)==0)
                        printf("\n��ͨ��û�����Ŷӣ�\n\n");
                    else
                    {
                        printf("\n��ͨ�����������Ŷӣ�\n\n");
                        n = GetQueue(Q1);
                        printf("\n�� %d �ˣ�\n\n",n);
                    }      break;
            case 3: if(Judge(Q2)!=0)
                    {
                        DeQueue(Q2,name);
                        printf("�����Ǽ���ĳ���,�����ǣ� %s\n\n",name);
                        continue;
                    }
                    if(Judge(Q2)==0 && Judge(Q1)!=0)
                    {
                        
                        DeQueue(Q1,name);
                        printf("��������ͨ��ĳ���,�����ǣ� %s\n\n",name);continue;
                    }
                    if(Judge(Q1)==Judge(Q2) && Judge(Q2)==0)
                        printf("�Ѿ�û�����ˣ�\n\n");
                   break;
            case 4:printf("�˳�ϵͳ��\n");
                    free(Q1);free(Q2);
                     return 0;
            default:printf("��������������룡\n");
                          break;
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
        return 0;
    else
        return OK;
}

Status GetQueue(LinkQueue *Q)           //������
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