#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    
    double xa,ya,xb,yb;
    
    scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
    double x=xb-xa;
    double y=yb-ya;
    double r=sqrt(x*x+y*y);
    double theta=atan2(x,y);
    printf("%.4lf %.4lf\n", r, fmod(theta/acos(-1)*180.0+360.0,360.0));
    return 0;
}
