/*
编写程序显示单月的日历，星期日在最后一列，星期一在第一列，以此类推。
*/
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
    int a,b;
    while (scanf("%d", &a) != EOF) {
        getchar();
        char c1=getchar(),c2=getchar();
        if(c1=='+'){
            scanf("%d",&b);
            printf("%d\n",a+b);
        }
        else if(c1=='-'){
            scanf("%d",&b);
            printf("%d\n",a-b);
        }
        else if(c1=='*'){
            if(c2==' '){
                scanf("%d",&b);
                printf("%d\n",a*b);
            }else{
                scanf("%d",&b);
                printf("%d\n",power(a,b));
            }
        }
        else if(c1=='/'){
            if(c2==' '){
                scanf("%d",&b);
                printf("%d\n",a/b);
            }
            else {
                scanf("%d",&b);
                double a0=a,b0=b;
                printf("%.3lf\n",a0/b0);
            }
        }
        else if(c1=='%'){
            scanf("%d",&b);
            printf("%d\n",a%b);
        }
        while(getchar()!='\n'){}
    }
    return 0;
}