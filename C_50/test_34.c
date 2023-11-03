#include<stdio.h>
int main(){
    int cnt1=0,cnt2=0 ;
    int n ;
    scanf("%d",&n) ;
    int a[4] ;
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]) ;
        if(a[1]==(a[0]+a[2])&&(a[3]!=(a[0]+a[2]))){
            cnt2++ ;
        }
        if(a[3]==(a[0]+a[2]) &&a[1]!=(a[0]+a[2])){
            cnt1++ ;
        }
    }
    printf("%d %d",cnt1,cnt2) ;
}