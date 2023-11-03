#include<stdio.h>
int main(){
    int a,b,c ;
    scanf("%d %d",&a,&b) ;
    int pa=a,pb=b ;
    do{
    c=a%b ;
    if(c==0){
       break ;
    }
    else{
        a=b ;
        b=c ;
    }
    }while(1) ;
    printf("%d",pa*pb/b) ;
    return 0 ;
}