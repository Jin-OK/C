#include <stdio.h>
#define N 10
#define OK 1
#define EOF 0

int i;
static int count = 0,k = 0;

int input(int* a,int* b);
int Derivation(int* a,int* b,int* c,int* d);
int output(int* c,int* d);

int main()
{
    int arr1[N],arr2[N],arr3[N],arr4[N];
    input(arr1,arr2);
    Derivation(arr1,arr2,arr3,arr4);
    output(arr3,arr4);
    return EOF;

}


int input(int* a,int* b)
{
    char s;
    for (i=0; i<100 && s!='\n'; i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
        s = getchar();
        count++;
    }
    return OK;   
}

int Derivation(int* a,int* b,int* c,int* d)
{
    for(i=0;i<count;i++)
    {
        if(b[i]!=0)
        {
            c[i] = a[i]*b[i];
            d[i] = b[i]-1;
            k++;
        }      
    }
    return OK;
}

int output(int* c,int* d)
{
    for(i=0;i<k-1;i++){
         printf("%d ",c[i]);
         printf("%d ",d[i]);
    }
    printf("%d ",c[i]);
    printf("%d",d[i]);
    return OK;
}