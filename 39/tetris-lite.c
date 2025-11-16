#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int max(int a,int b){
    return a>b ? a:b;
}
int main(){
    int W,k,l=0,h=0;
    scanf("%d%d",&W,&k);
    bool a[30][8005];
    //bool dead[8005];
    //for(int i=0;i<=8000;i++) dead[i]=0;
    for(int i=0;i<=25;i++) for(int j=0;j<8000;j++) a[i][j]=0;

    for(int t=1;t<=k;t++){
        int flag,pos;
        scanf("%d%d",&flag,&pos);
        if(flag==1){
            int i;
            for(i=8000;i>0;i--) if(a[pos][i-1]) break;
            a[pos][i]=1;
            a[pos][i+1]=1;
            a[pos][i+2]=1;
            a[pos][i+3]=1;
            h=max(i+3,h);
        }else{
            int i;
            for(i=8000;i>0;i--) if(a[pos][i-1]||a[pos+1][i-1]||a[pos+2][i-1]||a[pos+3][i-1]) break;
            a[pos][i]=1;
            a[pos+1][i]=1;
            a[pos+2][i]=1;
            a[pos+3][i]=1;
            h=max(i,h);
        }
        for(int i=0;i<=8000;i++){
            //if(dead[i])continue;
            bool e0=0,e1=0;
            for(int j=1;j<=W;j++){
                if(a[j][i]) e1=1;
                else e0=1;
            }
            if(e0&&!e1) break;
            if(e1&&!e0){
                l++;
                //dead[i]=1;
                for(int j=i;j<=h+3;j++){////////////////////////////////////////////////
                    for(int jj=1;jj<=W;jj++){
                        a[jj][j]=a[jj][j+1];
                    }
                }
                i--;
                h--;
            }
        }
    }
    h++;
    printf("%d %d\n",h,l);
    for(int i=h-1;i>=0;i--){
        //if(dead[i]) continue;
        for(int j=1;j<=W;j++){
            if(a[j][i])printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}