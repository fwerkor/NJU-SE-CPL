#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int max(int a,int b){
    return a>b?a:b;
}
int maxx(int a,int b,int c,int d){
    return max(max(a,b),max(c,d));
}
int tx[250000],ty[250000];
bool tused[250000];
int bt[100000],br[100000],bc[100000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+5][m+5];
    for(int i=0;i<=n*m;i++)tused[i]=0;
    for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++) a[i][j]=0;
    int t=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        tx[a[i][j]]=i;
        ty[a[i][j]]=j;
        tused[a[i][j]]=1;
    }
    for(int ttt=1;ttt<=n*m;ttt++)if(tused[ttt]){
        int flag=0;
        tx[ttt]--;
        ty[ttt]--;
        if(maxx(a[tx[ttt]][ty[ttt]],a[tx[ttt]][ty[ttt]+1],a[tx[ttt]+1][ty[ttt]],a[tx[ttt]+1][ty[ttt]+1])==ttt) {
            if(a[tx[ttt]][ty[ttt]]!=0&&a[tx[ttt]][ty[ttt]+1]!=0&&a[tx[ttt]+1][ty[ttt]]!=0&&a[tx[ttt]+1][ty[ttt]+1]!=0){
                bt[t]=ttt;
                br[t]=tx[ttt];
                bc[t]=ty[ttt];
                t++;
                a[tx[ttt]][ty[ttt]]=0;
                a[tx[ttt]][ty[ttt]+1]=0;
                a[tx[ttt]+1][ty[ttt]]=0;
                a[tx[ttt]+1][ty[ttt]+1]=0;
                flag++;
            }
        }
        ty[ttt]++;
        if(flag==0)if(maxx(a[tx[ttt]][ty[ttt]],a[tx[ttt]][ty[ttt]+1],a[tx[ttt]+1][ty[ttt]],a[tx[ttt]+1][ty[ttt]+1])==ttt) {
            if(a[tx[ttt]][ty[ttt]]!=0&&a[tx[ttt]][ty[ttt]+1]!=0&&a[tx[ttt]+1][ty[ttt]]!=0&&a[tx[ttt]+1][ty[ttt]+1]!=0){
                bt[t]=ttt;
                br[t]=tx[ttt];
                bc[t]=ty[ttt];
                t++;
                a[tx[ttt]][ty[ttt]]=0;
                a[tx[ttt]][ty[ttt]+1]=0;
                a[tx[ttt]+1][ty[ttt]]=0;
                a[tx[ttt]+1][ty[ttt]+1]=0;
                flag++;
            }
        }
        tx[ttt]++;
        ty[ttt]--;
        if(flag==0)if(maxx(a[tx[ttt]][ty[ttt]],a[tx[ttt]][ty[ttt]+1],a[tx[ttt]+1][ty[ttt]],a[tx[ttt]+1][ty[ttt]+1])==ttt) {
            if(a[tx[ttt]][ty[ttt]]!=0&&a[tx[ttt]][ty[ttt]+1]!=0&&a[tx[ttt]+1][ty[ttt]]!=0&&a[tx[ttt]+1][ty[ttt]+1]!=0){
                bt[t]=ttt;
                br[t]=tx[ttt];
                bc[t]=ty[ttt];
                t++;
                a[tx[ttt]][ty[ttt]]=0;
                a[tx[ttt]][ty[ttt]+1]=0;
                a[tx[ttt]+1][ty[ttt]]=0;
                a[tx[ttt]+1][ty[ttt]+1]=0;
                flag++;
            }
        }
        ty[ttt]++;
        if(flag==0)if(maxx(a[tx[ttt]][ty[ttt]],a[tx[ttt]][ty[ttt]+1],a[tx[ttt]+1][ty[ttt]],a[tx[ttt]+1][ty[ttt]+1])==ttt) {
            if(a[tx[ttt]][ty[ttt]]!=0&&a[tx[ttt]][ty[ttt]+1]!=0&&a[tx[ttt]+1][ty[ttt]]!=0&&a[tx[ttt]+1][ty[ttt]+1]!=0){
                bt[t]=ttt;
                br[t]=tx[ttt];
                bc[t]=ty[ttt];
                t++;
                a[tx[ttt]][ty[ttt]]=0;
                a[tx[ttt]][ty[ttt]+1]=0;
                a[tx[ttt]+1][ty[ttt]]=0;
                a[tx[ttt]+1][ty[ttt]+1]=0;
                flag++;
            }
        }
        
        
        
    }
    printf("%d\n",t);
    for(int i=0;i<t;i++)printf("%d %d.5 %d.5\n",bt[i],br[i],bc[i]);
    return 0;
}