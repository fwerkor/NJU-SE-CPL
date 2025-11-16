#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
bool doit(){
    char a[100005];
    scanf("%100003s",a);
    char stack[100005];
    int t=0;
    int len = strlen(a);
    for(int i=0;i<len;i++){
        if(a[i]=='('||a[i]=='['||a[i]=='{') stack[t++]=a[i];
        if(a[i]==')'){
            if(t==0||stack[t-1]!='(') return 0;
            t--;
        }if(a[i]==']'){
            if(t==0||stack[t-1]!='[') return 0;
            t--;
        }if(a[i]=='}'){
            if(t==0||stack[t-1]!='{') return 0;
            t--;
        }
    }
    if(t==0) return 1;
    else return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)printf(doit()?"True\n":"False\n");
    return 0;
}