#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int main(){
    int n;
    double x,s=0;
    scanf("%lf %d",&x,&n);
    for(int i=0;i<=n;i++){
        double t=2*i+1;
        s+=4.0*pow(-1,i)*pow(x,t)/t;
    }
    printf("%.10lf",s);
    return 0;
}