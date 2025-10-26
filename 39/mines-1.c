#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    bool a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char t;
            scanf("%c", &t);
            if(t=='*')a[i][j]=1;
            else a[i][j]=0;
        }
        getchar();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]){
                printf("*");
                continue;
            }
            int s=0;
            for(int i0=-1;i0<=1;i0++)for(int j0=-1;j0<=1;j0++)if(i+i0>=0&&i+i0<n&&j+j0>=0&&j+j0<n&&a[i+i0][j+j0])s++;
            printf("%d", s);
        }
        printf("\n");
    }
    return 0;
}