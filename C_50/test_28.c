#include<stdio.h>
#include<string.h>
int Max(int a,int b){
    if(a>b) return a ;
    else return b ;
}
int main(){
    int n ;
    scanf("%d",&n) ;
    getchar() ;
    int c[100][26]={0} ;
    for(int i=0;i<n;i++){
        char a[100];
        int max = 0 ;
        int temp = 0 ;
        int x ;
        scanf("%s",&a) ;
        for(int j=0;j<strlen(a);j++){
            c[i][a[j]-'a']++ ;
            temp=Max(max,c[i][a[j]-'a']) ;
            if(temp>max){
                x=a[j]-'a' ;
                max=temp ;
            }
        }
        printf("%c %d\n",'a'+x,c[i][x]) ;
        
    }
    return 0 ;
}