#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int ans[20];
    ans[1]=0;//
    ans[2]=0;//
    ans[3]=3;//
    ans[4]=0;////
    ans[5]=0;//////
    ans[6]=0;//
    ans[7]=0;//
    ans[8]=0;//
    ans[9]=0;//
    ans[10]=0;//
    ans[11]=0;//
    ans[12]=0;//
    ans[13]=0;//
    ans[14]=14;////
    ans[15]=15;//
    ans[16]=16;//
    ans[17]=0;//
    ans[18]=18;//
    int n;
    scanf("%d", &n);
    int s1=-1,s2=0,s3=0;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        s1&=ans[t];
        s2|=ans[t];
        s3^=ans[t];
    }
    printf("%d %d %d\n",s1,s2,s3);
    return 0;
}