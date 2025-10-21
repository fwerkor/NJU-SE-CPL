#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char a[10005],b[10005],c[10005],op;
bool mycomp(){
    int i=strlen(a)-1,j=strlen(b)-1;
    if(i>j) return 1;
    if(i<j) return 0;
    while(i>=0){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
        i--;
    }
    return 1;
}
void myadd(){
    int i=strlen(a)-1,j=strlen(b)-1,k=0,t=0;
    while(i>=0||j>=0||t!=0){
        int x=i>=0?a[i]-'0':0;
        int y=j>=0?b[j]-'0':0;
        c[k++]=(x+y+t)%10+'0';
        t=(x+y+t)/10;
        i--;
        j--;
    }
    c[k]='\0';
    for(int i=0,j=k-1;i<j;i++,j--){
        char t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
void mysub(){
    if (!mycomp()){
        printf("-");
        char t=*a;
        *a=*b;
        *b=t;
    }
    int i=strlen(a)-1,j=strlen(b)-1,k=0,t=0;
    while(i>=0||j>=0||t!=0){
        int x=i>=0?a[i]-'0':0;
        int y=j>=0?b[j]-'0':0;
        c[k++]=(x-y+t)%10+'0';
        t=(x-y+t)/10;
        i--;
        j--;
    }
    c[k]='\0';
    for(int i=0,j=k-1;i<j;i++,j--){
        char t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
void mymul(){
    int i=strlen(a)-1,j=strlen(b)-1,k=0,t=0;
    while(i>=0||j>=0||t!=0){ 
        int x=i>=0?a[i]-'0':0;
        int y=j>=0?b[j]-'0':0;
        c[k++]=(x*y+t)%10+'0';
        t=(x*y+t)/10;
        i--;
        j--;
    }
    c[k]='\0';
    for(int i=0,j=k-1;i<j;i++,j--){
        char t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
void mydiv(){
    int i=strlen(a)-1,j=strlen(b)-1,k=0,t=0;
    while(i>=0||j>=0||t!=0){
        int x=i>=0?a[i]-'0':0;
        int y=j>=0?b[j]-'0':0;
        c[k++]=(x/y+t)%10+'0';
        t=(x/y+t)/10;
        i--;
        j--;
    }
    c[k]='\0';
    for(int i=0,j=k-1;i<j;i++,j--){
        char t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    /*char ans[n+5][10005];*/
    for(int i=1;i<=n;i++) {
        scanf("%s %c %s",a,&op,b);
        if(op=='+')myadd();
        if(op=='-')mysub();
        if(op=='*')mymul();
        if(op=='/')mydiv();
        /*for(int j=0;j<strlen(c);j++) ans[i][j]=c[j];
        ans[i][strlen(c)]='\0';*/
        printf("%s\n",c);
    }
    /*for(int i=1;i<=n;i++) printf("%s\n",ans[i]);*/
    return 0;
}