#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int m,n,p;
    scanf("%d%d%d", &m, &n, &p);
    int a[m][n],b[n][p],c[m][p];
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d", &a[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<p;j++)scanf("%d", &b[i][j]);
    for(int i=0;i<m;i++)for(int j=0;j<p;j++){
        c[i][j]=0;
        for(int k=0;k<n;k++)c[i][j]+=a[i][k]*b[k][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<p-1;j++)printf("%d ", c[i][j]);
        printf("%d\n",c[i][p-1]);
    }
    return 0;
}