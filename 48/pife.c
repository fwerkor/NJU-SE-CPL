#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    char *a=malloc(sizeof(char)*1020);
    char *next=malloc(sizeof(char)*1020);
    memset(a,'.',sizeof(char)*1020);
    scanf("%d%s",&n,a+10);
    strncpy(next, a, 1020);
    int t=strlen(a+10);
    for(int i=1;i<=n;i++){
        for(int j=0;j<t;j++){
            int A=((*(a+10+j-3)=='A')?1:0)+((*(a+10+j-2)=='A')?1:0)+((*(a+10+j-1)=='A')?1:0)+((*(a+10+j+1)=='A')?1:0)+((*(a+10+j+2)=='A')?1:0)+((*(a+10+j+3)=='A')?1:0);
            int B=((*(a+10+j-3)=='B')?1:0)+((*(a+10+j-2)=='B')?1:0)+((*(a+10+j-1)=='B')?1:0)+((*(a+10+j+1)=='B')?1:0)+((*(a+10+j+2)=='B')?1:0)+((*(a+10+j+3)=='B')?1:0);
            if(*(a+10+j)=='.'){
                if(A>=2&&A<=4&&B==0) *(next+10+j)='A';
                if(B>=2&&B<=4&&A==0) *(next+10+j)='B';
            }
            if(*(a+10+j)=='A'){
                if(B>0) *(next+10+j)='.';
                else if(A>=5||A<=1) *(next+10+j)='.';
            }
            if(*(a+10+j)=='B'){
                if(A>0) *(next+10+j)='.';
                else if(B>=5||B<=1) *(next+10+j)='.';
            }
        }
        strncpy(a, next, 1020);
    }
    for(int i=0;i<t;i++) printf("%c",*(a+i+10));
    puts("");
    return 0;
}

