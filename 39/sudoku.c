#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int a[9][9];
    for(int i=0;i<9;i++)for(int j=0;j<9;j++)scanf("%d", &a[i][j]);
    bool flag[10000];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)flag[j]=0;
        for(int j=0;j<9;j++)flag[a[i][j]]=1;
        for(int j=1;j<10;j++)if(flag[j]==0){
            printf("NO\n");
            return 0;
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)flag[j]=0;
        for(int j=0;j<9;j++)flag[a[j][i]]=1;
        for(int j=1;j<10;j++)if(flag[j]==0){
            printf("NO\n");
            return 0;
        }
    }
    for(int i=1;i<=7;i+=3)for(int j=1;j<=7;j+=3){
        for(int k=0;k<9;k++)flag[k]=0;
        for(int i0=-1;i0<=1;i0++)for(int j0=-1;j0<=1;j0++)flag[a[i+i0][j+j0]]=1;
        for(int k=1;k<10;k++)if(flag[k]==0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}