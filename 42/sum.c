#include<stdlib.h>
#include<stdio.h>
int power(int n){
    int s=1;
    while(n--) s*=10;
    return s;
}
int num(int i,int t){
    int s=0;
    for(int j=0;j<i;j++) s+=power(j)*t;
    return s;
}
int main(){
    int n,t,s=0;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++) s+=num(i,t);
    printf("%d\n",s);
    return 0;
}