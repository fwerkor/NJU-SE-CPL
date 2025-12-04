#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
void doit(){
    char s1[1001],s2[1001];
    int ds1,ds2,size;
    getchar();
    int t=0;
    while(1){
        char tt=getchar();
        if(tt==';'){
            s1[t]='\0';
            break;
        }
        s1[t]=tt;
        t++;
    }
    t=0;
    while(1){
        char tt=getchar();
        if(tt==';'){
            s2[t]='\0';
            break;
        }
        s2[t]=tt;
        t++;
    }
    scanf("%d;%d;%d",&ds1,&ds2,&size);
    size--;
    char s3[2002];
    t=0;
    int t1=0,t2=0,len1=strlen(s1),len2=strlen(s2);
    while(1){
        if(t==size)break;
        if(t1==len1&&t2==len2)break;
        for(int i=0;i<ds1;i++){
            if(t==size||t1==len1)break;
            s3[t]=s1[t1];
            t1++;
            t++;
        }
        for(int i=0;i<ds2;i++){
            if(t==size||t2==len2)break;
            s3[t]=s2[t2];
            t2++;
            t++;
        }
    }
    s3[t]='\0';
    printf("%s\n",s3);
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        doit();
    }
    return 0;
}