#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char a[10001],b[10001],c[10001];
void add(){
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
int main(){
    while (scanf("%s %s", a,b) != EOF) {
        add();
        printf("%s\n",c);
    }
    return 0;
}