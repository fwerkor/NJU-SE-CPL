#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    long long n,r,m,d,L;
    scanf("%lld%lld%lld%lld",&n,&r,&m,&d);
    long long a[n+1];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    long long left=-1,right=r-1;
    while(1){
        L=(left+right+1)/2;
        if(left==right) break;
        long long k=0,s=0;
        for(int i=0;i<n;i++) if(a[i]<r&&a[i]>L){
            k++;
            s+=a[i]-L;
        }
        if(k<m||s<d) right=L-1;
        else left=L;
    }
    if(right==-1) printf("-1\n");
    else printf("%d\n",L);
    return 0;
}