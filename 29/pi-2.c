#include <stdio.h>
#include <math.h>
int main(){
    
    
    double pi;
    double i=236674+30303*sqrt(61);
    i=i*i*i;
    pi=log(5280.0*5280.0*5280.0*i+744)/sqrt(427);
    printf("%.15f\n", pi);


    pi=6*atan(1.0/8.0)+2*atan(1.0/57.0)+atan(1.0/239.0);
    pi*=4;
    printf("%.15f\n", pi);
    return 0;
}