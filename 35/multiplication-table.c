#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            printf("%dx%d=%d ",j,i,i*j);
        }
        printf("%dx%d=%d\n",i,i,i*i);
    }
    return 0;
}