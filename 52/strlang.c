#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char a[50000001];
void myremove(int start,int len){
    char *aa=a;//
    int lena=strlen(a);
    for(int i=0;i<=lena-start;i++){
        a[start+i]=a[start+len+i];
        if(a[start+i]=='\0') break;
    }
}
void myadd(int start,char s[]){
    char *aa=a;//
    int lena=strlen(a),len=strlen(s);
    for(int i=lena;i>=start;i--) a[i+len]=a[i];
    for(int i=0;i<len;i++) a[start+i]=s[i];
}
bool process(char mod1,char str1[],char mod2,char str2[]){
    char *aa=a;//
    int len1=strlen(str1),len2=strlen(str2),len=strlen(a);
    if(len1>len) return 0;
    if(mod1=='^'){
        if(!strncmp(a,str1,len1)==0) return 0;
        myremove(0,len1);
        if(mod2=='^') myadd(0,str2);
        if(mod2=='$') myadd(len-len1,str2);
        if(mod2=='.') myadd(0,str2);
    }
    if(mod1=='$'){
        if(!strncmp(a+len-len1,str1,len1)==0) return 0;
        myremove(len-len1,len1);
        if(mod2=='^') myadd(0,str2);
        if(mod2=='$') myadd(len-len1,str2);
        if(mod2=='.') myadd(len-len1,str2);
    }
    if(mod1=='.'){
        bool flag=0;
        int i;
        for(i=0;i<=len-len1;i++) if(strncmp(a+i,str1,len1)==0){
                flag=1;
                break;
        }
        if(!flag) return 0;
        myremove(i,len1);
        if(mod2=='^') myadd(0,str2);
        if(mod2=='$') myadd(len-len1,str2);
        if(mod2=='.') myadd(i,str2);
    }
    return 1;
}
int main(){
    char *opss=malloc(sizeof(char)*500000001),*ops=opss,*op[400];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        op[i]=ops;
        scanf("%s",ops);
        ops+=strlen(ops)+1;
    }
    ops=opss;
    scanf("%s",a);
    bool flag=1;
    int t;
    char mod1=ops[0],*str1=malloc(sizeof(char)*10000001),*i,mod2,*str2=malloc(sizeof(char)*10000001);
    while(flag){
        flag=0;
        for(int j=0;j<n;j++){
            ops=op[j];
            mod1=ops[0];
            int t=0;
            for(i=ops+2;*i!=']';i++){
                str1[t]=*i;
                t++;
            }
            str1[t]='\0';
            i++;
            mod2=*i;
            t=0;
            for(i+=2;*i!=']';i++){
                str2[t]=*i;
                t++;
            }
            str2[t]='\0';
            if(process(mod1,str1,mod2,str2)){
                flag=1;
                break;
            }
        }
    }
    puts(a);
    free(opss);
    free(str1);
    free(str2);
    return 0;
}