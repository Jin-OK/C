#include <stdio.h>
int main()
{
    int n,p,i,j,sum = 0;
    scanf("%11d %11d",&n,&p);
    if(n>=2 && n<=100000) 
    {
        int a[n];
        for(i=0;i<n;i++)
            scanf("%11d",&a[i]);
        for(i=0;i<=n-1;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(a[i]+a[j]>p && a[i]+p>a[j] && p+a[j]>a[i])
                    sum++;
            }
        }
        printf("%d",sum);
    }
    return 0;
}