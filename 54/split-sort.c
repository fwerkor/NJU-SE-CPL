#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char aa[100000],s;
char a[105][105];
int t=0,tt=0;
int cmp(const void *ta, const void *tb) {
    return strcmp((const char*)ta, (const char*)tb);
}
int main(){
    scanf("%s\n%c",aa,&s);
    int len=strlen(aa);
    for(int i=0;i<=len;i++){
        if(aa[i]==s){
            a[t][tt]='\0';
            tt=0;
            t++;
        }else{
            a[t][tt]=aa[i];
            tt++;
        }
    }
    qsort(a,t+1,105*sizeof(char),cmp);
    for(int i=0;i<=t;i++)printf("%s\n",a[i]);
    return 0;
}