#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
bool doit(){
    char a0[501],s[501];
    bool fu=0;
    scanf("%500s",a0);
    if(a0[0]=='-'){
        fu=1;
        a0[0]='0';
    }
    for(int i=0;i<strlen(a0);i++) if(!isdigit(a0[i])){
        puts("Radix Error");
        return 0;
    }
    int a;
    if(!fu){
        a=atoi(a0);
    }else{
        char *num_str = a0;
        num_str = a0 + 1;
        a=atoi(num_str);
    }
    int t=0;
    while(a>0){
        s[t]='0'+a%3;
        a/=3;
        t++;
    }
    for(int i=0;i<t-1;i++){
        switch(s[i]){
            case '2':
                s[i]='Z';
                s[i+1]++;
                break;
            case '3':
                s[i]='0';
                s[i+1]++;
                break;
        }        
    }
    switch(s[t-1]){
        case '2':
            s[t-1]='Z';
            s[t]='1';
            t++;
            break;
        case '3':
            s[t-1]='0';
            s[t]='1';
            t++;
            break;
    }
    for(int i=0;i<t/2;i++){
        char tmp=s[i];
        s[i]=s[t-i-1];
        s[t-i-1]=tmp;
    }
    if(fu){
        for(int i=0;i<t;i++){
            if(s[i]=='1') s[i]='Z';
            else if(s[i]=='Z') s[i]='1';
        }
    }
    if(t==0){
        puts("0");
        return 1;
    }
    printf("%.*s\n",t,s);
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        doit();
    }
    return 0;
}