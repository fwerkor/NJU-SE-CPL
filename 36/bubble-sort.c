
/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}
bool doit(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    qsort(b, n, sizeof(int), cmpfunc);
    for(int i=1;i<n-1;i++) if( a[i]<b[i-1] || a[i]>b[i+1] ) return 0;
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        if(doit()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool doit(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i = 0; i < n-1; i++) {
        if(a[i]>a[n-1]) return 0;
    }
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        if(doit()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}