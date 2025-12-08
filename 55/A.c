#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
long long a[10001],map[10001],n;
void swap(long long *a,long long *b){
    long long tt=*a;
    *a=*b;
    *b=tt;
}
void sort(){
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if(a[map[i]]<a[map[j]]){
                swap(&map[i],&map[j]);
            }
        }
    }
}
bool ma(long long size){
    if(a[map[0]]<size) return 0;
    a[map[0]]-=size;
    long long i;
    long long ttt=map[0];
    for(i=1;i<n;i++){
        map[i-1]=map[i];
        if(a[map[i]]==a[ttt]&&map[i]>ttt) break;
        if(a[map[i]]<a[ttt]){
            break;
        }
    }
    if(i==n)i--;
    map[i]=ttt;
    return 1;
}
void pr(){
    for(long long i=0;i<n-1;i++)printf("%lld ",a[i]);
    printf("%lld\n",a[n-1]);
}
int main(){
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
        map[i]=i;
    }
    sort();
    char op[101];
    long long t=0;
    while(1){
        t++;
        scanf("%s",op);
        if(op[0]=='m'){
            long long tt;
            scanf("%lld",&tt);
            if(!ma(tt)) break;
        }else{
            pr();
        }
    }
    printf("%lld\n",t);
    pr();
    return 0;
}