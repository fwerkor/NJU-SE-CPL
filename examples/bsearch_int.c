#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int n,q,a[1000001];
int cmp(const void *a,const void *b){
    int *pa=(int*)a,*pb=(int*)b;
    if(*pa<*pb)return -1;
    if(*pa>*pb)return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    while(q--){
        int t;
        scanf("%d",&t);
        int *p=(int*)bsearch(&t,a,n,sizeof(int),cmp);
        if(p) printf("%d\n",p-a);
        else printf("-1\n");
    }
    return 0;
}