#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    printf("%d\n", a/50);
    a = a%50;
    printf("%d\n", a/20);
    a = a%20;
    printf("%d\n", a/10);
    a = a%10;
    printf("%d\n", a/5);
    a = a%5;
    printf("%d\n", a);
    return 0;
}