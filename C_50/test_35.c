#include<stdio.h>
void sort(double* a,int left,int right){
     if(left>=right) return ;
     int i=left;
     int j=right ;
     int mid = (left+right)/2 ;
     double temp = a[mid] ;
     while(i<=j){
        while(a[j]>temp) j-- ;
        while(a[i]<temp) i++ ;
        if(i<=j){
            double tmp = a[i] ;
            a[i]=a[j] ;
            a[j]=tmp ;
            i++ ;
            j-- ;
        }
     }
     sort(a,left,j) ;
     sort(a,i,right) ;
}
int main(){
    int n ;
    scanf("%d",&n) ;
    double max[105] ;
    double a[105] ;
    for(int i=0;i<n;i++){
        int num ;
        scanf("%d",&num) ;
        for(int j=0;j<num;j++){
            scanf("%lf",&a[j]) ;
        }
        sort(a,0,num-1) ;
        max[i]=a[num-1] ;
    }
    for(int i = 0;i<n;i++){
        printf("%.2f\n",max[i]) ;
    }
    return 0 ;
}