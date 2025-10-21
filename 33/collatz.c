#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int max(int a,int b){
    return a>=b ? a:b;
}
int main(){
    int n,step=0,m;
    scanf("%d",&n);
    m=n;
    while(n>1){
        step+=1;
        if(n%2==0) n/=2;
        else{
            n=3*n+1;
            m=max(n,m);
        }
    }
    printf("%d %d\n",step,m);
    return 0;
}