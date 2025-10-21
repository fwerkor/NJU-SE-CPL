#include <stdio.h>
#include <stdbool.h>
int main(){
    int n,a;
    scanf("%d",&n);
    bool t[10*n+1];
    for(int i=1;i<=10*n;i++){
        t[i]=0;
    }
    for(int i=0;i<2*n-1;i++){
        scanf("%d",&a);
        if(t[a]){t[a]=0;}
        else{t[a]=1;}
    }
    for(int i=1;i<=10*n;i++){
        if(t[i]){
            printf("%d\n",i);
        }
    }
    return 0;
}