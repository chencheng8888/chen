#include<stdio.h>
int main(){
    int T ;
    scanf("%d",&T);//先输入组数
    for(int i=1;i<=T;i++){
        long long A,B,C;
        scanf("%lld %lld %lld",&A,&B,&C);
        //输入这三个数
        if(A+B>C){
            printf("Case #%d: true\n",i) ;
        }
        else{
            printf("Case #%d: false\n",i);
        }
    }
    return 0 ;
}