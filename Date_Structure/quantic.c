#include <stdio.h>
int main()
{
    int a[1000],i = 0,n = 0,x = 0,sum = 0;
    printf("��Ҫ���뼸������ʽ�� ");
    scanf("%d",&n);
    printf("������x��ֵ�� ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        printf("������� %d ������ʽ�� ",i+1);
        scanf("%d",&a[i]);
        sum += (x*a[i]);
    }
    printf("����ʽ��Ӻ� %d\n",sum);
}