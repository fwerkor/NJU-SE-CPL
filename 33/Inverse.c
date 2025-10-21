#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int main(){
    int n,k;
    scanf("%d",&n);
    char a[n+1];
    getchar();
    for(int i=0;i<n;i++) a[i]=getchar();
    scanf("%d",&k);
    for(int i=k-1;i>=0;i--) printf("%c",a[i]);
    for(int i=n-1;i>=k;i--) printf("%c",a[i]);
    printf("\n");
    return 0;
}