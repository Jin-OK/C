#include <stdio.h>
int main()
{
    int a[1000],i = 0,n = 0,x = 0,sum = 0;
    printf("你要输入几个多项式： ");
    scanf("%d",&n);
    printf("请输入x的值： ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        printf("请输入第 %d 个多项式： ",i+1);
        scanf("%d",&a[i]);
        sum += (x*a[i]);
    }
    printf("多项式相加后： %d\n",sum);
}