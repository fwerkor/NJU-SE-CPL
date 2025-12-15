#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int a[5][5],b[5],s=0;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        scanf("%d",&a[i][j]);
    }
    scanf("%d%d%d",&b[0],&b[1],&b[2]);
    for(int i1=0;i1<3;i1++)for(int j1=0;j1<3;j1++){
        for(int i2=0;i2<3;i2++)for(int j2=0;j2<3;j2++){
            for(int i3=0;i3<3;i3++)for(int j3=0;j3<3;j3++){
                if((i1==i2&&j1==j2)||(i1==i3&&j1==j3)||(i3==i2&&j3==j2))continue;
                if((i1+i3==2*i2&&j1+j3==2*j2)||(i1+i2==2*i3&&j1+j2==2*j3)||(i2+i3==2*i1&&j2+j3==2*j1))continue;
                int t=b[0]*a[i1][j1]+b[1]*a[i2][j2]+b[2]*a[i3][j3];
                if(s<t){
                    s=t;
                }
            }
        }
    }
    printf("%d\n",s);
}
