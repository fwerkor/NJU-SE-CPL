#include<stdlib.h>
#include<stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int k=n-1,f=n-1;
    while(a[k-1]>a[k]) k--;
    k--;
    while(a[k]>=a[f]) f--;
    swap(&a[k],&a[f]);
    for(int i=0;i<=k;i++) printf("%d ",a[i]);
    for(int i=n-1;i>=k+1;i--) printf("%d ",a[i]);
    printf("\n");
    return 0;
}