#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=0;
    int x=0,y=n/2;
    a[x][y]=1;
    for(int i=2;i<=n*n;i++){
        int x0=x,y0=y;
        if(a[x][y]!=0)
        x--;y++;
        if(x==-1)x=n-1;
        if(y==n)y=0;
        if(a[x][y]!=0){
            x=x0+1;y=y0;
        }
        a[x][y]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++)printf("%d ", a[i][j]);
        printf("%d\n",a[i][n-1]);
    }
    return 0;
}