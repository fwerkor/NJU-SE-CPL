#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    
    double p,q;
    scanf("%lf %lf", &p, &q);
    double a,b;
    a=-q/2.0+sqrt(q*q/4.0+p*p*p/27.0);
    b=-q/2.0-sqrt(q*q/4.0+p*p*p/27.0);
    if(a<0){a=-pow(-a,1.0/3.0);}else{a=pow(a,1.0/3.0);}
    if(b<0){b=-pow(-b,1.0/3.0);}else{b=pow(b,1.0/3.0);}
    printf("%.3lf\n", a+b);
    return 0;
}
