#include<stdio.h>
#include<string.h>
int main(){
    char A[12],B[12] ;
    char a,b ;
    int cnt1 = 0,cnt2=0 ;
    int num1=0,num2=0 ;
    scanf("%s %c %s %c",&A,&a,&B,&b) ;
    for(int i=0;i<strlen(A);i++){
        if(A[i]==a){
            cnt1++ ;
            num1=10*num1+(A[i]-'0') ;
        }
    }
    for(int i=0;i<strlen(B);i++){
        if(B[i]==b){
            cnt2++ ;
            num2=10*num2+(B[i]-'0') ;
        }
    }
    printf("%d",num1+num2) ;
    return 0 ;
}