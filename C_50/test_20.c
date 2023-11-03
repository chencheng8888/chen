#include<stdio.h>
double  Pow(double x,int y){
    double product=1 ;
    for(int i=1;i<=y;i++){
        product *= x ;
    }
    return product ;
}
int main(){
    int n,p ;
    double x ;
    scanf("%d %lf",&n,&x) ;
    p=n ;
    double num=0 ;
    for(int i=1;i<=n+1;i++){
        double a ;
        scanf("%lf",&a) ;
        num+=(a*Pow(x,p)) ;
        p-- ;
    }
    printf("%.3lf",num) ;
    return 0 ;
}