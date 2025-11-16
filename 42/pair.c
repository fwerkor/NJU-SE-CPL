#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,m,t,s=1000000001;
    scanf("%d%d%d",&n,&m,&t);
    int a[n],b[m];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) 
    {
        scanf("%d",&b[i]);
        if(t-a[0]-b[i]<0) continue;
        int l=0,r=n-1,mid;
        while(l<r)
        {
            mid=(l+r+1)/2;
            if(t-b[i]-a[mid]>=0) l=mid;
            else r=mid-1;
        }
        mid=(l+r+1)/2;
        if(t-b[i]-a[mid]<s) s=t-b[i]-a[mid];
    }
    if(s==1000000001) printf("-1\n");
    else printf("%d\n",s);
    return 0;
}