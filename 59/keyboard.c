#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char a[5000000],t[5000000];
int to=0;
bool e[5000000];
int main(){
    int q;
    int last_b=-1,last_s=-1;
    scanf("%d",&q);
    while(q--){
        scanf("%s",t);
        if(t[0]=='?'){
            int k;
            scanf("%d",&k);
            for(int i=0;i<k;i++){
                if(!e[to-1-i]){
                    k++;
                }
            }
            for(int i=0;i<k;i++){
                if(e[to-k+i])printf("%c",a[to-k+i]);
            }
            puts("");
        }else{
            int len=strlen(t);
            for(int i=0;i<len;i++){
                if(t[i]=='M'||t[i]=='m'){
                    if(t[i]=='M'){
                        if(last_b==-1)continue;
                        e[last_b]=0;
                        for(int j=last_b-1;j>=0;j--){
                            if(e[j]&&a[j]<='Z'&&a[j]>='A'){
                                last_b=j;
                                break;
                            }
                        }
                    }
                    if(t[i]=='m'){
                        if(last_s==-1)continue;
                        e[last_s]=0;
                        for(int j=last_s-1;j>=0;j--){
                            if(e[j]&&a[j]<='z'&&a[j]>='a'){
                                last_s=j;
                                break;
                            }
                        }
                    }
                    
                }else{
                    if(t[i]<='Z'&&t[i]>='A'){
                        last_b=to;
                    }
                    if(t[i]<='z'&&t[i]>='a'){
                        last_s=to;
                    }
                    a[to]=t[i];
                    e[to]=1;
                    to++;
                }
            }
        }
    }
    return 0;
}