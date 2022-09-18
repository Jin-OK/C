#include<stdio.h>
#include<math.h>
char key[100000001];             
long long z,flag = 3,N,result=0;

void Change(long long num){    
    long long op = num;
    do{
        key[op] = '}';
        op+=num;
    } while (op<=N);
}

void SU(long long num){ 
    long long len = sqrt(num)+1;
    while (flag<=len){
        if(num%len==0) return ;
        flag+=2;
    }
    Change(num);
    result++;
}

int main(void){

    scanf("%lld",&N);
    if(N>=2) {
        result++;
        Change(2);
    }
    for(z=3;z<=N;z+=2){
        if(key[z]=='}') continue;
        SU(z);
    }
    printf("%lld",result);
    return 0;
}