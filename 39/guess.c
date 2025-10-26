#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    long long unsigned int left=0,right=4294967295;
    while(1){
        long long unsigned int mid=(left+right)/2;
        printf("%u\n", mid);
        char s[10];
        fflush(stdout);
        scanf("%s",s);
        if(s[0]=='G')right=mid-1;
        if(s[0]=='L')left=mid+1;
        if(s[0]=='E')break;
    }
    return 0;
}