#include <stdio.h>
#include <stdlib.h>
#define OK 1

typedef int Status;

typedef struct Node
{
    int nummber;
    struct Node *next;
}Node,*NodePtr;

Status InitLink(Node *L);               //初始化
Status InputLink(Node *L,int n);        //插入元素n
Status LinkDelete(Node *L,int i);       //删除第i个元素
Status DoLink(Node *L,int n,int m);     //n个猴子从0报数到m

Status main()
{
    Node a,*L = &a;
    int n,m;
    InitLink(L);
    scanf("%d%d",&n,&m);
    InputLink(L,n);
    DoLink(L,n,m);
	//free(L);
    return 0;
}

Status InitLink(Node *L)
{
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    return OK;
}

Status InputLink(Node *L,int n)
{
    int i;
    NodePtr p,q;
    q = L;
    for(i=0;i<n;i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->nummber = i;
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

Status LinkDelete(Node *L,int i)
{
    Node *p = NULL,*q = NULL;
    int j;
    p = L;
    while((p->next) && (j<i-1))
    {
        p = p->next;++j;       //p指向删除元素前一个
    }
    q = p->next;
    p->next = q->next;
    return OK;
}

Status DoLink(Node *L,int n,int m)
{
    Node* p = NULL;
    int i,k,t;            //i为报数，k为计数
    p = L;
    for(k=1,i=0;i<m;i++,k++)
    {
        p = p->next;
        if(i==m-1)
        {
            LinkDelete(L,k);
            i=-1;
   			k--;
			--n;
        }
    	if(k==n)
        {
        	p = L;
        	k = 0;
        }
            
        if(n==1) break;
		t = L->next->nummber;
    }
    printf("%d\n",t);
    return OK;
}