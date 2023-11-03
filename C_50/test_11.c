#include<stdio.h>
int main(){
    int  m;
    long long n ;
    scanf("%lld %d",&n,&m);
    long long a[12] ;
    for(long long i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<=m){
                scanf("%lld",&a[j]) ;
                i++;
                if(i==m){  //当输完m个数就直接排序
                    for(int k=1;k<=m;k++){
                    for(int l=k+1;l<=m;l++){    
                        long long temp;
                        if(a[k]<a[l]){
                            temp=a[k] ;
                            a[k]=a[l] ;
                            a[l]=temp ;
                        }
                    }
                }
                }
            } //先把m个数先输进去
            else{
            scanf("%lld",&a[m+1]) ;
            i++ ;
            if(a[m+1]<a[m]) continue ; //如果新输入的数比最后一个小，直接继续输入；
            int j ;
            long long temp = a[m+1] ;
            for( j=m-1;j>0&&a[j]<temp;j--){
                a[j+1]=a[j] ;
            }   a[j+1]=temp ;//将这个数插入到这m个数中
            }//因为这m个数已经排好了，所以排序的时间短
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",a[i]) ;//输出前m个数
    }
    return 0 ;
}