#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    if(n==1)n=8;
    n--;
    int m0=m;
    for(int i=1;i<=4*n-6;i++){
        printf(" ");
    }
    while(m>0){
        if(n!=1)printf("%4d",m0-m+1);
        else printf("%2d",m0-m+1);
        m--;
        n++;
        if(n==8){
            n=1;
            printf("\n");
        }
    }
    return 0;
}