#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int n;
typedef struct team{
    char name[25];
    int s1,s2,s3;
}Team;
Team a[1001]={0};
int cmp1(const void *tta,const void *ttb){
    const Team *ta=(const Team*)tta,*tb=(const Team*)ttb;
    if((ta->s1)>(tb->s1))return -1;
    if((ta->s1)<(tb->s1))return 1;
    return 0;
}
int cmp2(const void *tta,const void *ttb){
    const Team *ta=(const Team*)tta,*tb=(const Team*)ttb;
    if((ta->s2)>(tb->s2))return -1;
    if((ta->s2)<(tb->s2))return 1;
    return 0;
}
int cmp3(const void *tta,const void *ttb){
    const Team *ta=(const Team*)tta,*tb=(const Team*)ttb;
    if((ta->s3)>(tb->s3))return -1;
    if((ta->s3)<(tb->s3))return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i].name);
        char tt[25];
        int t1,t2,t3;
        for(int j=0;j<11;j++){
            scanf("%s%d%d%d",tt,&t1,&t2,&t3);
            a[i].s1+=t1;
            a[i].s2+=t2;
            a[i].s3+=t3;
        }
    }
    qsort(a,n,sizeof(Team),cmp1);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
    puts("");
    qsort(a,n,sizeof(Team),cmp2);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
    puts("");
    qsort(a,n,sizeof(Team),cmp3);
    for(int i=0;i<n;i++){
        printf("%s ",a[i].name);
    }
    puts("");
    
    return 0;
}