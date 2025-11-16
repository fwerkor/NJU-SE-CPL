#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char t=getchar();
    printf("%c",(t<='z'&&t>='a')?t-32:t);
    while(1){
        t=getchar();
        if(t=='\n') break;
        if(t==' '){
            printf(" ");
            t=getchar();
            printf("%c",(t<='z'&&t>='a')?t-32:t);
            continue;
        }
        printf("%c",(t<='Z'&&t>='A')?t+32:t);
    }
    puts("");
    return 0;
}

