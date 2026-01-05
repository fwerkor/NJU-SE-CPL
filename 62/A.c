#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    int next;
    int prev;
} node;
node a[10000000];
int tt=0,head=0,tail=0,len=0;

int dw(int pos){
    int cur;
    if(pos<len/2){
        cur=head;
        for(int i=0;i<pos-1;i++){
            cur=a[cur].next;
        }
    }else{
        cur=tail;
        for(int i=0;i<len-pos;i++){
            cur=a[cur].prev;
        }
    }
    return cur;
}

void insert(int pos, char ch){
    a[tt].ch=ch;
    if(pos==0){
        a[tt].next=head;
        a[head].prev=tt;
        head=tt;
    }
    if(pos==len){
        a[tt].prev=tail;
        a[tail].next=tt;
        tail=tt;
    }
    if(pos<len&&pos>0){
        int cur=dw(pos);
        a[tt].prev=cur;
        a[tt].next=a[cur].next;
        a[a[cur].next].prev=tt;
        a[cur].next=tt;
    }
    len++;
    tt++;
}

void delete(int prev, int next){
    if(prev==0){
        head=next;
        len-=next-prev-1;
        return;
    }
    if(next==len+1){
        tail=prev;
        len-=next-prev-1;
        return;
    }
    int prevpos=dw(prev);
    int nextpos=dw(next);
    a[prevpos].next=nextpos;
    a[nextpos].prev=prevpos;
    len-=next-prev-1;
}

int main() {
    char s[10001];
    scanf("%s",s);
    int len0=strlen(s);
    for(int i=0;i<len0;i++){
        insert(i,s[i]);
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        char ch;
        scanf("%d %c",&n,&ch);
        insert(n,ch);
        int qian=-1,hou=-1,cur;
        cur=dw(n+1);
        while(a[cur].ch==ch&&cur!=head){
            cur=a[cur].prev;
            qian++;
        }
        if(cur==head&&a[cur].ch==ch)qian++;
        cur=dw(n+1);
        while(a[cur].ch==ch&&cur!=tail){
            cur=a[cur].next;
            hou++;
        }
        if(cur==tail&&a[cur].ch==ch)hou++;
        if(qian+hou+1>=3){
            delete(n-qian,n+hou+2);
        }
    }
    printf(len==0?"Congratulations!\n":"%d\n",len);
    return 0;
}