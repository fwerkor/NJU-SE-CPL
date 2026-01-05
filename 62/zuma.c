#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int t=0;
typedef struct node{
    char ch;
    struct node* next;
    struct node* prev;
}node;
typedef struct LL {
    node *head, *tail;
} LL;
LL a;
node* insert(node *prev, node *next, char color){
    node* new=malloc(sizeof(node));
    prev->next=new;
    next->prev=new;
    new->next=next;
    new->prev=prev;
    new->ch=color;
    t++;
    return new;
}
void delete(node *prev, node *next,int num){
    if(prev)prev->next=next;
    else a.head=next;
    if(next)next->prev=prev;
    else a.tail=prev;
    t-=num;
}
node* add(int pos,char co){
    if(t==0){
        node* new=malloc(sizeof(node));
        new->ch=co;
        new->next=NULL;
        new->prev=NULL;
        a.head=new;
        a.tail=new;
        t++;
        return new;
    }else if(pos==0){
        node* new=malloc(sizeof(node));
        new->ch=co;
        new->next=a.head;
        new->prev=NULL;
        a.head->prev=new;
        a.head=new;
        t++;
        return new;
    }else if(pos==t){
        node* new=malloc(sizeof(node));
        new->ch=co;
        new->prev=a.tail;
        new->next=NULL;
        a.tail->next=new;
        a.tail=new;
        t++;
        return new;
    }else if(pos<t/2){
        node* cur=a.head;
        while(pos--)cur=cur->next;
        return insert(cur,cur->next,co);
    }else{
        pos=t-pos;
        node* cur=a.tail;
        while(pos--)cur=cur->prev;
        return insert(cur,cur->next,co);
    }
}
void doit(){
    int pos;
    char co;
    scanf("%d %c",&pos,&co);
    node* cur1=add(pos,co);
    node* cur2=cur1;
    int qian=0,hou=0;
    while(cur1->prev&&cur1->prev->ch==co){
        qian++;
        cur1=cur1->prev;
    }
    while(cur2->next&&cur2->next->ch==co){
        hou++;
        cur2=cur2->next;
    }
    if(qian+hou+1>=3){
        if(cur1&&cur2)delete(cur1->prev,cur2->next,qian+hou+1);
        if(cur1&&!cur2)delete(cur1->prev,NULL,qian+hou+1);
        if(!cur1&&cur2)delete(NULL,cur2->next,qian+hou+1);
        if(!cur1&&!cur2)delete(NULL,NULL,qian+hou+1);
    }
}
int main(){
    char s[10000];
    int n;
    scanf("%s%d",s,&n);
    int len=strlen(s);
    a.head=NULL;
    a.tail=NULL;
    while(len--)add(0,s[len]);
    while(n--)doit();
    printf(t==0?"Congratulations!\n":"%d\n",t);
    return 0;
}