#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    int ansx[100000],ansy[100000],ansn=0;
    scanf("%d%d%d",&n,&m,&d);
    int a[n+2*d+100][m+2*d+100];
    for(int i=0;i<=n+2*d+50;i++) for(int j=0;j<=m+2*d+50;j++) a[i][j]=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[d+i][d+j]);
    int x,y;
    long long s=-9223372036854775807,ss;
    for(int i=1;i<=n;i++){
        x=d+i;
        ss=0;
        y=d+1;
        for(int i0=-d;i0<=d;i0++) for(int j0=-d;j0<=d;j0++) if(abs(i0)+abs(j0)<=d) ss+=a[x+i0][y+j0];
        if(ss==s){
            ansx[ansn]=i;
            ansy[ansn]=1;
            ansn++;
        }
        if(ss>s){
            s=ss;
            ansn=0;
            ansx[ansn]=i;
            ansy[ansn]=1;
            ansn++;
        }
        for(int j=2;j<=n;j++){
            y=d+j;
            for(int t=0;t<=d;t++){
                ss-=a[x+t][y-d+t-1];
                if(t!=0) ss-=a[x-t][y-d+t-1];
                ss+=a[x+t][y+d-t];
                if(t!=0) ss+=a[x-t][y+d-t];
            }
            if(ss==s){
                ansx[ansn]=i;
                ansy[ansn]=j;
                ansn++;
            }
            if(ss>s){
                s=ss;
                ansn=0;
                ansx[ansn]=i;
                ansy[ansn]=j;
                ansn++;
            }
        }
    }
    printf("%lld %d\n",s,ansn);
    for(int i=0;i<ansn;i++) printf("%d %d\n",ansx[i],ansy[i]);
    return 0;
}