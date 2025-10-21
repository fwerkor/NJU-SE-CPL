#include <stdio.h>
int max(int a,int b,int c){
    if(a>b && a>c)return a;
    return b>c ? b:c;
}
int min(int a,int b,int c){
    if(a<b && a<c)return a;
    return b<c ? b:c;
}
int main(){
    int n,m=0;
    scanf("%d",&n);
    int a=n/100,b=n/10%10,c=n%10;
    int np=(max(a,b,c)-min(a,b,c))*99;
    while(n!=495){
        
        if(n>np)m+=n-np;
        
        n=np;
        a=n/100;
        b=n/10%10;
        c=n%10;
        np=(max(a,b,c)-min(a,b,c))*99;
    }
    printf("%d\n",m);
    return 0;
}