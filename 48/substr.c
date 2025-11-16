#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char *str=malloc(sizeof(char)*100001);
    char *substr=malloc(sizeof(char)*100001);
    scanf("%s%s",str,substr);
    int n=strlen(str),m=strlen(substr);
    for(int i=0;i<=n-m;i++){
        bool flag=true;
        for(int j=0;j<m;j++) if(*(str+i+j)!=*(substr+j)) flag=false;
        if(flag) printf("%d ",i);
    }
    puts("");
    return 0;
}

