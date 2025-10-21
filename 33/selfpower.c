#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
long long powp(long long a,long long b){
    long long sss=1;
    for(int i=1;i<=b;i++)sss*=a;
    return sss;
}
int main(){
    long long n,ss=0,s[101],mi=0;
    scanf("%lld",&n);
    while(n/powp(10,mi)!=0) {
        s[mi]=n/powp(10,mi)%10;
        mi++;
    }
    for(int i=0;i<mi;i++){
        ss+=powp(s[i],mi);
    }
    if(ss==n) printf("%d\n",mi);
    else printf("0\n");
    return 0;
}