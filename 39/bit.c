#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int power(int n,int m){
    int s=1;
    while(m--)s*=n;
    return s;
}
int main(){
    int a,b;
    scanf("%d%d", &a, &b);
    printf("%d\n",a&b);
    printf("%d\n",a|b);
    printf("%d\n",a^b);
    printf("%d\n",~a);
    printf("%d\n",a<<b);
    printf("%d\n",a>>b);
    printf("%d\n",a/power(2,b)%2);
    int s=0;
    while(a!=0){
        s+=a%2;
        a/=2;
    }
    printf("%d\n", s);
    return 0;
}