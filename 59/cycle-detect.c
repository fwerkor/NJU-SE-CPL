#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
    char name[30];
    int target;
}node;
node a[100005];
int main(){
    int n,t=1,h=1,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%d",a[i].name,&a[i].target);
        if(a[i].target<1||a[i].target>n)a[i].target=0;
    }
    a[0].target=0;
    while(1){
        t=a[t].target;
        h=a[h].target;
        h=a[h].target;
        if(h==0){
            printf("-1\n");
            exit(0);
        }
        if(t==h)break;
    }
    t=1;
    while(1){
        if(t==h)break;
        t=a[t].target;
        h=a[h].target;
    }
    printf("%s\n",a[t].name);
    return 0;
}