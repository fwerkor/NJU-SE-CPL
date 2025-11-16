#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    unsigned int a,*pp=&a;
    scanf("%x",&a);
    float *p=(float *)pp;
    printf("%d\n%u\n%f\n%.3e\n",a,a,*p,*p);
    return 0;
}