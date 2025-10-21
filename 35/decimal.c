#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int power(int a,int b){
    int ans=1;
    for(int i=0;i<b;i++) ans*=a;
    return ans;
}
int main(){
    int len,N,ans=0;
    scanf("%d%d",&len,&N);
    char a[len+1];
    scanf("%s",a);
    for(int i=len-1;i>=0;i--){
        int t;
        if(a[i]>='0'&&a[i]<='9') t=a[i]-'0';
        else t=a[i]-'A'+10;
        if(t>=N) {
            printf("Error\n");
            return 0;
        }
        ans+=t*power(N,len-1-i);
    }
    printf("%d\n",ans);
    return 0;
}