#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int main(){
    long long n,s=0,jc=1;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        jc*=i;
        jc%=1000000007;
        s+=jc;
        s%=1000000007;
    }
    printf("%lld",s);
    return 0;
}