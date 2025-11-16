#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    int a[h][w],k[3][3];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)scanf("%d",&k[i][j]);
    for(int i=0;i<h-2;i++)
    {
        for(int j=0;j<w-2;j++){
            int s=0;
            for(int m=0;m<=2;m++)for(int n=0;n<=2;n++)s+=a[i+m][j+n]*k[m][n];
            printf("%d ",s);
        }
        puts("");
    }
    return 0;
}