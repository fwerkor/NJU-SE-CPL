#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int maxx(int a,int b,int c,int d,int e,int f){
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
    if(e>max) max=e;
    if(f>max) max=f;
    return max;
}
int main(){
    int p,q,r,b=2;
    scanf("%d%d%d",&p,&q,&r);
    int p1=p/10, p0=p%10;
    int q1=q/10, q0=q%10;
    int r1=r/10, r0=r%10;
    for(b=maxx(p0,q0,r0,p1,q1,r1)+1;b<=40;b++){
        int qq=q1*b+q0;
        int pp=p1*b+p0;
        int rr=r1*b+r0;
        if(qq*pp==rr) break;
    }
    if(b==41){
        printf("0\n");
        return 0;
    }else{
        printf("%d\n",b);
    }
    return 0;
}