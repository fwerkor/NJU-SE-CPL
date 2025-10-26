#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    int a[n][m];
    int px[n*m/2+1][2],py[n*m/2+1][2];
    for(int i=0;i<n*m/2+1;i++)px[i][0]=-1;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        scanf("%d",&a[i][j]);

        //New locating method!
        if(px[a[i][j]][0]==-1){
            px[a[i][j]][0]=i;
            py[a[i][j]][0]=j;
        }else{
            px[a[i][j]][1]=i;
            py[a[i][j]][1]=j;
        }
    }
    for(int c=1;c<=n*m/2;c++){
        int x1,y1,x2,y2;
        bool t=0;
        
        /*
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(a[i][j]==c){
                if(!t){
                    x1=i;y1=j;
                    t=1;
                }else x2=i;y2=j;
            }
        }
        This will cause Timeout! (A30%)
        */
        x1=px[c][0];y1=py[c][0];
        x2=px[c][1];y2=py[c][1];

        t=1;
        for(int i=0;i<x1;i++)if(a[i][y1]!=0)t=0;
        for(int i=0;i<x2;i++)if(a[i][y2]!=0)t=0;
        if(t){
            printf("%d ",c);
            a[x1][y1]=0;
            a[x2][y2]=0;
            continue;
        }

        t=1;
        for(int i=0;i<y1;i++)if(a[x1][i]!=0)t=0;
        for(int i=0;i<y2;i++)if(a[x2][i]!=0)t=0;
        if(t){
            printf("%d ",c);
            a[x1][y1]=0;
            a[x2][y2]=0;
            continue;
        }

        t=1;
        for(int i=x1+1;i<n;i++)if(a[i][y1]!=0)t=0;
        for(int i=x2+1;i<n;i++)if(a[i][y2]!=0)t=0;
        if(t){
            printf("%d ",c);
            a[x1][y1]=0;
            a[x2][y2]=0;
            continue;
        }

        t=1;
        for(int i=y1+1;i<m;i++)if(a[x1][i]!=0)t=0;
        for(int i=y2+1;i<m;i++)if(a[x2][i]!=0)t=0;
        if(t){
            printf("%d ",c);
            a[x1][y1]=0;
            a[x2][y2]=0;
            continue;
        }

    }
    return 0;
}