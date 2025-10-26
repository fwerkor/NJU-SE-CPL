#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int a[2000],n;
int check(){
    int d=0;
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            if(d>0)return 0;
            else d=i;
        }
    }
    return d;
}
int main(){
    int k,b,l;
    scanf("%d%d%d%d", &n, &k, &b, &l);
    int bu=b,cu=1,ku=0;
    for (int i=1;i<=n;i++)a[i]=l;
    while(check()==0){
        ku++;
        if(ku==k){
            ku=0;
            if(bu==0){
                bu=b;
            }else{
                bu--;
                a[cu]--;
            }
        }
        cu++;
        if(cu==n+1)cu=1;
        while(a[cu]==0){
            cu++;
            if(cu==n+1)cu=1;
        }
    }
    printf("%d\n", check());
    return 0;
}