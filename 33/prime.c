#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
bool blacklist[50000001];
int ss=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) blacklist[i]=0;
    if(n>=2) ss++;
    for(long long i=3;i<=n;i+=2){
        if(!blacklist[i]){
            ss++;
            for(long long j=i*i;j<=n;j+=2*i) blacklist[j]=1;
        }
    }
    printf("%d\n",ss);
    return 0;
}
