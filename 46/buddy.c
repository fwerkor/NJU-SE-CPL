#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int a[100000],b[100000],t;
void initialize(int m0){
    t=1;
    a[0]=0;
    b[0]=m0;
}
void cut(int pos){
    for(int i=t;i>pos;i--){
        a[i]=a[i-1];
        b[i]=b[i-1];
    }
    t++;
    b[pos+1]-=1;
    b[pos]=b[pos+1];
}
int power(int s){
    int ans=1;
    for(int i=0;i<s;i++) ans*=2;
    return ans;
}
int op_m(int n){
    int s=0;
    while(power(s)<n) s++;
    return s;
}
void op_a(int id,int m){
    for(int i=0;i<t;i++){
        if(a[i]==0&&b[i]==m){
            a[i]=id;
            return;
        }
    }
    for(int i=0;i<t;i++){
        if(a[i]==0&&b[i]>m){
            cut(i);
            return op_a(id,m);
        }
    }
}
void op_q(){
    printf("%d\n",t);
    for(int i=0;i<t-1;i++) printf("%d ",a[i]);
    printf("%d\n",a[t-1]);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    initialize(n);
    while(q--){
        char tt='0';
        while(tt!='A'&&tt!='Q') tt=getchar();
        if(tt=='A'){
            int id,m0;
            scanf("%d%d",&id,&m0);
            int m=op_m(m0);
            op_a(id,m);
        }else if(tt=='Q'){
            op_q();
        }
    }
    return 0;
}