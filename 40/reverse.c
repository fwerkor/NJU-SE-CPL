#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[n+1];
    scanf("%s", a);
    for (int i=n-1;i>=0;i--){
        if(a[i]>='A'&&a[i]<='Z'){
            a[i]+=32;
        }
        else if(a[i]>='a'&&a[i]<='z'){
            a[i]-=32;
        }
        printf("%c", a[i]);
    }
    printf("\n");
}