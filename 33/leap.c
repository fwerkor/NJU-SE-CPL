#include <stdio.h>
int main(){
    int h,m;
    scanf("%d:%d",&h,&m);
    if(h<=11) printf("%02d:%02d a.m.\n",h,m);
    else if(h<=12) printf("%02d:%02d p.m.\n",h,m);
    else printf("%02d:%02d p.m.\n",h-12,m);
    return 0;
}