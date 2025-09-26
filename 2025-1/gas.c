#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    
    double R=8.314;
    double P,T,L;
    
    scanf("%lf %lf %lf", &P, &L, &T);
    double V=L*L*L;
    double n=P*V/(R*T);
    printf("%.4le\n", n);
    return 0;
}
