#include <stdio.h>
int main(){
    int n,a,s=0,sa=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&a);
        if(a!=0 && sa<i){
            s+=i-sa;
            sa+=i-sa;
        }
        sa+=a;
    }
    printf("%d\n",s);
    return 0;
}