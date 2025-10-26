#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    bool sup=1,supsup=1;
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0;i<n;i++)scanf("%d", &a[i]);
    for(int i=0;i<n-1;i++)if(a[i]>a[i+1])sup=0;
    for(int i=1;i<n-1;i++)if(!(a[i-1]<=a[i]&&a[i]<=a[i+1]&&a[i+1]-a[i]>a[i]-a[i-1]))supsup=0;
    if(supsup)printf("1\n");
    else if(sup)printf("0\n");
    else printf("-1\n");
    return 0;
}