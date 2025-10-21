#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int n,k;
bool a[600];

bool check(){
    int s=0;
    for(int i=1;i<=n;i++) if(!a[i]) s++;
    return s==1 ? 0:1;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) a[i]=0;
    int t=0,l=k;
    while(check()){
        l--;
        t++;
        a[0]=a[n];
        while(a[t%n]) t++;
        if(t>n) t%=n;
        if(l==0){
            l=k;
            a[t]=1;
        }
    }
    for(int i=1;i<=n;i++) if(!a[i]) printf("%d\n",i);
    return 0;
}