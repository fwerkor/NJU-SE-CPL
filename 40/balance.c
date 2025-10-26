#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,s=0;
    scanf("%d",  &n);
    int a[100005],t=0;
    while(n>0){
        a[t++]=n%5;
        n/=5;
    }
    int ji=0;
    for(int i=0;i<t;i++){
        a[i]+=ji;
        ji=0;
        if(a[i]==3){
            a[i]=-2;
            ji=1;
        }
        if(a[i]==4){
            a[i]=-1;
            ji=1;
        }
        if(a[i]==5){
            a[i]=0;
            ji=1;
        }
    }
    if(ji==1)a[t++]=1;
    for(int i=0;i<t;i++)s+=abs(a[i]);
    printf("%d\n", s);
    return 0;
}