#include <stdio.h>
#define OK 1
#define EOF 0
#define N 100

int i;

int input(int* n,int* m,int* a);
int exchange(int* a,int n,int m);
int output(int* a,int n);

int main()
{
    int n,m;
    int arr[N];
    input(&n,&m,arr);
    exchange(arr,n,m);
    output(arr,n);
    return EOF;
}

int input(int* n,int* m,int* a)
{
    scanf("%d %d",n,m);
    for(i=0;i<*n;i++)
        scanf("%d",&a[i]);
    return OK;
}

int exchange(int* a,int n,int m)
{
    int temp,j;
    for(i=0;i<m;i++)
    {
        temp = a[0];
        for(j=0;j<n-1;j++)
            a[j] = a[j+1];
        a[j] = temp;
    }
    return OK;
}

int output(int* a,int n)
{
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
        return OK;
}