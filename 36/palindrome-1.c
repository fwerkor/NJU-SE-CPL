#include <stdio.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char a[n+1];
    scanf("%s",a);
    for(int i=0;i<n;i++){
        if(a[i]=='?'){
            a[i]=a[n-i-1];
        }
    }
    printf("%s\n",a);
    return 0;
}