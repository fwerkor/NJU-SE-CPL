#include <stdio.h>
#include <stdbool.h>
int main(){
    int n,s=0,jc[30];
    jc[1]=1;
    for(int i=2;i<=28;i++){
        jc[i]=i*jc[i-1]%10007;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        s+=jc[i];
        s%=10007;
    }
    printf("%d",s);
    return 0;
}