#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    int n;
    scanf("%d",&n);
    bool a[n+1];
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(a[j]) a[j]=0;
            else a[j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]) printf("%d ",i);
    }
    return 0;
}