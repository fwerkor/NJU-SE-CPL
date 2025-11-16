#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    bool a[x][y];
    for(int i=0;i<x;i++) for(int j=0;j<y;j++) {
        char t;
        scanf("%c",&t);
        if(t=='\n') scanf("%c",&t);
        a[i][j]=(t=='/');
    }
    int ans=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y-1;j++){
            if(a[i][j]&&!a[i][j+1]){
                for(int k=1;;k++){
                    if(i+2*k-1>=x||j+k>=y||j-k+1<0) break;
                    bool flag=1;
                    for(int l=0;l<k;l++){
                        if(!(a[i+l][j-l]&&!a[i+l][j+1+l]&&!a[i+k+l][j-k+l+1]&&a[i+k+l][j+k-l])) {
                            flag=0;
                            break;
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}