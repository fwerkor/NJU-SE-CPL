#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int min(int a,int b){
    return a<b?a:b;
}
void mystrcat(char* s1, char* s2){
    printf("%s",s1);
    int i,len1=strlen(s1),len2=strlen(s2);
    for(i=len1-min(len1,len2);i<len1;i++){
        bool flag=1;
        for(int j=i;j<len1;j++){
            if(*(s1+j)!=*(s2+j-i)){
                flag=0;
                break;
            }
        }
        if(flag)break;
    }
    char *p=s2+(len1-i);
    printf("%s\n",p);
}
int main(){
    int T;
    scanf("%d",&T);
    char *s1=malloc(sizeof(char)*1001);
    char *s2=malloc(sizeof(char)*1001);
    while(T--){
        scanf("%s %s",s1,s2);
        mystrcat(s1,s2);
    }
    return 0;
}