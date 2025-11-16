#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    bool con[1001],pos[1001];
    int ttc[m],ttr[m],tts[m][n],tti[m];
    for(int i=1;i<=n;i++) con[i]=0;
    for(int i=0;i<m;i++){
        tti[i]=0;
        scanf("%d%d",&ttc[i],&ttr[i]);
        for(int j=0;j<ttc[i];j++) scanf("%d",&tts[i][j]);
        if(ttr[i]==0){
            for(int j=0;j<ttc[i];j++){
                con[tts[i][j]]=1;
                pos[tts[i][j]]=0;
            }
            tti[i]=1;
        }
        if(ttr[i]==1&&ttc[i]==1){
            con[tts[i][0]]=1;
            pos[tts[i][0]]=1;
            tti[i]=1;
        }
    }
    while(1){
        bool flag=0;
        for(int i=0;i<m;i++){
            if(tti[i]==0){
                bool flagg=1;
                for(int j=0;j<ttc[i];j++){
                    if(con[tts[i][j]]&&pos[tts[i][j]]){
                        flagg=0;
                        break;
                    }
                }
                if(flagg==0){
                    tti[i]=1;
                }else{
                    flag=1;
                }
            }
        }
        if(flag==0)break;
        int jieshiliangmax=0,jieshizhe;
        for(int i=1;i<=n;i++){
            if(!con[i]){
                int tanengjieshi=0;
                for(int j=0;j<m;j++){
                    if(tti[j]==0){
                        for(int k=0;k<ttc[j];k++){
                            if(tts[j][k]==i){
                                tanengjieshi++;
                                break;
                            }
                        }
                    }
                }
                if(tanengjieshi>jieshiliangmax){
                    jieshiliangmax=tanengjieshi;
                    jieshizhe=i;
                }
            }
        }
        con[jieshizhe]=1;
        pos[jieshizhe]=1;
    }
    int numpos=0;
    for(int i=1;i<=n;i++){
        if(con[i]&&pos[i])numpos++;
    }
    printf("%d\n",numpos);
    for(int i=1;i<=n;i++){
        if(con[i]&&pos[i])printf("%d ",i);
    }
    puts("");
    return 0;
}