#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<=100 && n>=90) puts("A");
    if(n<=89 && n>=80) puts("B");
    if(n<=79 && n>=70) puts("C");
    if(n<=69 && n>=60) puts("D");
    if(n<=59 && n>=0) puts("F");
    if(n>=101) puts("Wrong score");
    return 0;
}