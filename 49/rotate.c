#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int x1q,x2q,y1q,y2q;
char op[10001];
void does(int a,int b,int c,int t){
    if(op[t]=='\0')return;
    if(op[t]=='W'){
        x2q=x1q;
        x1q=x2q-c;
        return does(c,b,a,t+1);
    }
    if(op[t]=='S'){
        x1q=x2q;
        x2q=x1q+c;
        return does(c,b,a,t+1);
    }
    if(op[t]=='A'){
        y2q=y1q;
        y1q=y2q-c;
        return does(a,c,b,t+1);
    }
    if(op[t]=='D'){
        y1q=y2q;
        y2q=y1q+c;
        return does(a,c,b,t+1);
    }
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%s",op);
    x1q=0;
    y1q=0;
    x2q=a;
    y2q=b;
    does(a,b,c,0);
    printf("%d %d %d %d\n",x1q,x2q,y1q,y2q);
    return 0;
}