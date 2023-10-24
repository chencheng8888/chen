#include<stdio.h>
int main()
{int n;
 int i=0;
 scanf("%d",&n);
 if(n==1) printf("%d",i) ;
 else{
     do{if(n%2==0);
else{n=3*n+1;}
 n=n/2;
 i++;}
 while(n!=1);
 printf("%d\n",i);
 }
 
 return 0;}