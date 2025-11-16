#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,s=0;
    scanf("%d",&n);
    int power[n+5];
    for(int i=0;i<n;i++){
        scanf("%d",&power[i]);
    }
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        if(power[j]-power[i]>s) s=power[j]-power[i];
    }
    printf("%d\n",s);
    return 0;
}