#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int x;
void doit(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int w[5]={0,0,0,0,0};
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int k=1;
            while(a[i+k][j]==a[i][j]&&i+k<n)k++;
            if(k>=x)w[a[i][j]]=1;
            k=1;
            while(a[i][j+k]==a[i][j]&&j+k<n)k++;
            if(k>=x)w[a[i][j]]=1;
            k=1;
            while(a[i+k][j+k]==a[i][j]&&i+k<n&&j+k<n)k++;
            if(k>=x)w[a[i][j]]=1;
            k=1;
            while(a[i+k][j-k]==a[i][j]&&i+k<n&&j-k>=0)k++;
            if(k>=x)w[a[i][j]]=1;
        }
    }

    if(w[1]+w[2]+w[4]>1 || w[1]+w[2]+w[4]==0){
        printf("draw\n");
    }else{
        if(w[1]==1)printf("1\n");
        if(w[2]==1)printf("2\n");
        if(w[4]==1)printf("4\n");
    }
}
int main(){
    int t;
    scanf("%d%d", &t, &x);
    while(t--)doit();
}