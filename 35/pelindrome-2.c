#include <stdio.h>
#include <string.h>
int main(){
    int n,to=0;
    char ans[200000],t='0',tj='1';
    scanf("%d",&n);
    char a[n+1];
    scanf("%s",a);
    for(int i=0;i<n;i++){
        if(a[i]=='?'){
            a[i]=a[n-i-1];
        }
    }
    for(int i=0;i<=(n-1)/2;i++){
        if(a[i]=='?'){
            ans[to]=t;
            to++;
            ans[to]=tj;
            to++;
            tj++;
            if(tj=='9'+1) 
            {
                tj='0';
                t++;
            }
        }
        else {
            ans[to]=a[i];
            to++;
        }
    }
    for(int i=0;i<to;i++){
        printf("%c",ans[i]);
    }
    for(int i=n/2+1;i>=0;i--){
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}