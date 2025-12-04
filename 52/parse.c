#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char rule[129],a[1025];
    scanf("%s\n%[^\n]",rule,a);
    int len=strlen(a),rulelen=strlen(rule);
    int i;
    for(i=0;i<len;i++){
        if(a[i]==' ')break;
        printf("%c",a[i]);
    }
    int ib=i;
    for(;i<len;i++){
        if(a[i]=='-'){
            i++;
            char t=a[i];
            bool flag=0,exv=0;
            for(int j=0;j<rulelen;j++){
                if(t==rule[j]){
                    flag=1;
                    if(j!=rulelen-1&&rule[j+1]==':'){
                        exv=1;
                    }
                    break;
                }
            }
            if(flag==0){
                printf(": invalid option -- '%c'\n",a[i]);
                return 0;
            }
            if(exv==1){
                if(i>=len-2){
                    printf(": option requires an argument -- '%c'\n",a[i]);
                    return 0;
                }
            }
            if(exv==1){
                i+=2;
                while(i<len&&a[i]!=' '){
                    i++;
                }
            }
        }
    }
    i=ib;
    puts("");
    for(;i<len;i++){
        if(a[i]=='-'){
            i++;
            char t=a[i];
            bool flag=0,exv=0;
            for(int j=0;j<rulelen;j++){
                if(t==rule[j]){
                    flag=1;
                    if(j!=rulelen-1&&rule[j+1]==':'){
                        exv=1;
                    }
                    break;
                }
            }
            if(exv==0){
                printf("%c",a[i]);
            }else{
                printf("%c=",a[i]);
                i+=2;
                while(i<len&&a[i]!=' '){
                    printf("%c",a[i]);
                    i++;
                }
            }
            puts("");
        }
    }
    return 0;
}