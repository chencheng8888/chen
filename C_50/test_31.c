#include<stdio.h>
int main(){
    int n ;
    scanf("%d",&n) ;
    int a[100][2] ;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]) ;
        if(a[i][0]%a[i][1]!=0){
            printf("NO\n") ;
        }
        else{
            printf("YES\n") ;
        }
    }
    
    return 0 ;
}