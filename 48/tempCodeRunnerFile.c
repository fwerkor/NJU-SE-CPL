#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char a[10001];
    fgets(a,10001,stdin);
    if(a[0]>='a'&&a[0]<='z')a[0]-=32;
    for(int i=1;i<strlen(a);i++){
        if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
        if(a[i]==' '){
            if(a[i+1]>='a'&&a[i+1]<='z')a[i+1]-=32;
            i++;
        }
    }
    printf("%s",a);
    return 0;
}


/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char a[10001],t=0;
    a[0]=getchar();
    if(a[t]>='a'&&a[t]<='z')a[t]-=32;
    t++;
    while(1){
        a[t]=getchar();
        if(a[t]>='A'&&a[t]<='Z')a[t]+=32;
        t++;
        if(a[t-1]=='\n')break;
        if(a[t-1]==' '){
            a[t]=getchar();
            if(a[t]>='a'&&a[t]<='z')a[t]-=32;
            t++;
        }
    }
    a[t]='\0';
    printf("%s\n",a);
    return 0;
}*/

/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char a[10001],t=0;
    a[0]=getchar();
    if(a[t]>='a'&&a[t]<='z')a[t]-=32;
    t++;
    while(scanf("%c",a[t])!=EOF){
        if(a[t]>='A'&&a[t]<='Z')a[t]+=32;
        t++;
        if(a[t-1]==' '){
            scanf("%c",a[t]);
            if(a[t]>='a'&&a[t]<='z')a[t]-=32;
            t++;
        }
    }
    t++;
    a[t]='\0';
    printf("%s\n",a);
    return 0;
}

*/