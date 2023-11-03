#include<stdio.h>
int main(){
    int n ;
    char a ;
    scanf("%d %c",&n,&a) ;
    double m ;
    int n_2 ;
    n_2= n/2 ;
    m= n/2.0 ;
    if(m!=n_2){
        n_2 ++ ;
    }
    for(int i=1;i<=n_2;i++){
        for(int j=1;j<=n;j++){
            if(i==1||i==n_2){
                printf("%c",a) ;
            }
            else {
                if(j==1||j==n){
                    printf("%c",a) ;
                }
                else {
                    printf(" ") ;
                }
            }
        }
        printf("\n") ;
    }

    return 0 ;
}