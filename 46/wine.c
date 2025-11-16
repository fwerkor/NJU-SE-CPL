#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
void swap_int(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n,L,ans=0;
    scanf("%d%d",&n,&L);
    int a[n],b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++) for(int j=0;j<i;j++) if(a[j]<a[i]){
        swap_int(&a[i],&a[j]);
        swap_int(&b[i],&b[j]);
    }
    for(int i=0;i<n;i++) if(L>=b[i]){
        L-=b[i];
        ans+=a[i]*b[i];
    }else{
        ans+=a[i]*L;
        L=0;
        break;
    }
    printf("%d\n",ans);
    return 0;
}