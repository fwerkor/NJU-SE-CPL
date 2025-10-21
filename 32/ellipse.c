#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,h,s,l;
    scanf("%lf%lf",&a,&b);
    double pi=acos(-1);
    h=(a-b)*(a-b)/(a+b)/(a+b);
    s=pi*a*b;
    l=pi*(a+b)*(1.0+3.0*h/(10.0+sqrt(4-3*h)));

    printf("%.2lf\n",s);
    printf("%.2lf\n",l);
    return 0;
}