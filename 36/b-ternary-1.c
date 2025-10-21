#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
bool doit(){
    char a[501];
    scanf("%500s",a);
    int s=0;
    for(int i=0;i<strlen(a);i++){
        switch(a[i]){
            case '0': break;
            case '1': 
                s+=pow(3,strlen(a)-i-1);
                break;
            case 'Z':
                s-=pow(3,strlen(a)-i-1);
                break;
            default: 
                puts("Radix Error");
                return 0;
        }
    }
    printf("%d\n",s);
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