#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int a1[100000005]={0},a2[100000005]={0};
int sss[100000005]={0};
int main(){
    int p1,p2;
    char s[20];
    scanf("%d%d%s",&p1,&p2,s);
    int p=p1>p2?p1:p2;
    for(int i=p1;i>=0;i--)scanf("%d",&a1[i]);
    for(int i=p2;i>=0;i--)scanf("%d",&a2[i]);

    bool h=1;
    for(int i=p;i>=0;i--){
        int t=0;
        t=a1[i]+a2[i];
        if(t==0)continue;
        if(!h&&t>0)printf("+");
        if(t==1&&i>1){
            printf("%s^%d",s,i);
            continue;
        }
        if(t==-1&&i>1){
            printf("-%s^%d",s,i);
            continue;
        }
        if(i==1){
            if(t==1){
                printf("%s",s);
                continue;
            }
            if(t==-1){
                printf("-%s",s);
                continue;
            }
            printf("%d%s",t,s);
            continue;
        }
        if(i==0){
            printf("%d",t);
            continue;
        }
        printf("%d%s^%d",t,s,i);
        h=0;
    }
    if(h)printf("0");
    puts("");

    h=1;
    for(int i=p;i>=0;i--){
        int t=0;
        t=a1[i]-a2[i];
        if(t==0)continue;
        if(!h&&t>0)printf("+");
        if(t==1&&i>1){
            printf("%s^%d",s,i);
            continue;
        }
        if(t==-1&&i>1){
            printf("-%s^%d",s,i);
            continue;
        }
        if(i==1){
            if(t==1){
                printf("%s",s);
                continue;
            }
            if(t==-1){
                printf("-%s",s);
                continue;
            }
            printf("%d%s",t,s);
            continue;
        }
        if(i==0){
            printf("%d",t);
            continue;
        }
        printf("%d%s^%d",t,s,i);
        h=0;
    }
    if(h)printf("0");
    puts("");

    for(int i=0;i<=p1;i++){
        for(int j=0;j<=p2;j++){
            sss[i+j]+=a1[i]*a2[j];
        }
    }
    h=1;
    for(int i=p*p;i>=0;i--){
        int t=sss[i];
        if(t==0)continue;
        if(!h&&t>0)printf("+");
        if(t==1&&i>1){
            printf("%s^%d",s,i);
            continue;
        }
        if(t==-1&&i>1){
            printf("-%s^%d",s,i);
            continue;
        }
        if(i==1){
            if(t==1){
                printf("%s",s);
                continue;
            }
            if(t==-1){
                printf("-%s",s);
                continue;
            }
            printf("%d%s",t,s);
            continue;
        }
        if(i==0){
            printf("%d",t);
            continue;
        }
        printf("%d%s^%d",t,s,i);
        h=0;
    }
    if(h)printf("0");
    puts("");
    
    return 0;
}