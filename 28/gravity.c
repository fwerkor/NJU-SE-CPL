#include <stdio.h>
#include <math.h>
int main(){
    double G=6.674e-11;
    double M=77.15;
    double m,R;
    scanf("%lf%lf",&m,&R);
    printf("%.3le\n",G*M*m/pow(R,2));
    return 0;
}