/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
    return -( *(int*)a - *(int*)b );
}
int main(){
    int n,r,m,d,L=-1;
    scanf("%d%d%d%d",&n,&r,&m,&d);
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), cmpfunc);
    int j=-1;
    a[n]=-1;
    for(int i=0;i<n;i++){
        if(j==-1&&a[i]<=r){
            j=i;
            i+=m-1;
        }
        if(j==-1) continue;
        int l=a[i]-1;
        test:
        int s=0;
        for(int t=j;t<=i;t++){
            s+=a[t]-l;
        }
        if(s>=d){
            L=l;
            break;
        }else if(l>a[i+1]){
            l--;
            goto test;
        }
        if(l<0) break;
    }
    printf("%d\n",L);
    return 0;
}
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,r,m,d,L;
    scanf("%d%d%d%d",&n,&r,&m,&d);
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int left=-1,right=r-1;
    while(1){
        L=(left+right+1)/2;
        if(left==right) break;
        int k=0,s=0;
        for(int i=0;i<n;i++) if(a[i]<r&&a[i]>L){
            k++;
            s+=a[i]-L;
        }
        if(k<m||s<d) right=L-1;
        else left=L;
    }
    if(right==-1) printf("-1\n");
    else printf("%d\n",L);
    return 0;
}