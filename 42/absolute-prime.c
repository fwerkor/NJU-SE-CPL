#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int power(int n){
    int s=1;
    while(n--) s*=10;
    return s;
}
int re(int n){
    int s=0;
    while(n>0){
        s*=10;
        s+=n%10;
        n/=10;
    }
    return s;
}
bool isprime(int n){
    for(int i=2;i<=sqrt(n);i++) if(n%i==0) return 0;
    return 1;
}
int main(){
    int n,s=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) if(isprime(i)&&isprime(re(i))) s++;
    printf("%d\n",s);
    return 0;
}