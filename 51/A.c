#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int v[1005];
double price[1005];
char name[1005][50];
int wine_n[1005][10005],wine_v[1005][10005],wine_c[1005];
int main(){
    int n,V,x;
    scanf("%d%d%d",&n,&V,&x);
    for(int i=0;i<n;i++){
        scanf("%d%lf%s",&v[i],&price[i],name[i]);
        wine_c[i]=1;
        wine_n[i][0]=i;
        wine_v[i][0]=v[i];
    }
    int a,b;
    for(int k=0;k<x;k++){
        scanf("%d%d",&a,&b);
        while(1){
            if(wine_c[a]==0) break;
            int bused=0;
            for(int i=0;i<wine_c[b];i++)bused+=wine_v[b][i];
            int last=V-bused;
            if(last==0)break;
            if(last>=wine_v[a][wine_c[a]-1]){
                wine_c[a]--;
                wine_v[b][wine_c[b]]=wine_v[a][wine_c[a]];
                wine_n[b][wine_c[b]]=wine_n[a][wine_c[a]];
                wine_c[b]++;
            }else{
                wine_v[a][wine_c[a]-1]-=last;
                wine_v[b][wine_c[b]]=last;
                wine_n[b][wine_c[b]]=wine_n[a][wine_c[a]-1];
                wine_c[b]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(wine_c[i]==0){
            printf("0.00\n");
            continue;
        }
        double pp=0;
        for(int j=0;j<wine_c[i];j++)pp+=price[wine_n[i][j]]*wine_v[i][j];
        printf("%.2lf ",pp);
        for(int j=wine_c[i]-1;j>0;j--){
            printf("%s:%d,",name[wine_n[i][j]],wine_v[i][j]);
        }
        printf("%s:%d\n",name[wine_n[i][0]],wine_v[i][0]);
    }
    return 0;
}