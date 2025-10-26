#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int n,a[105][105],b[105][105];
long long c[105][105];
void op1(){
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=a[i][j]+b[i][j];
}
void op2(){
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=a[i][j]-b[i][j];
}
void op3(){
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        long long sum=0;
        for(int k=0;k<n;k++)sum+=a[i][k]*b[k][j];
        c[i][j]=sum;
    }
}
void op4(){
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=a[j][i];
}
int main(){
    int op;
    scanf("%d%d", &op,&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d", &a[i][j]);
    if(op!=4)for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d", &b[i][j]);
    if(op==1)op1();
    if(op==2)op2();
    if(op==3)op3();
    if(op==4)op4();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++)printf("%lld ", c[i][j]);
        printf("%lld\n", c[i][n-1]);
    }
    return 0;
}