/*
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Block {
    int start;          
    int size_power;     
    int id;             
    struct Block* next; 
} Block;

Block* head = NULL;


int calc_k(int m) {
    int k = 0;
    int size = 1;
    while (size < m) {
        k++;
        size *= 2;
    }
    return k;
}


void insert_block(int start, int size_power, int id) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    new_block->start = start;
    new_block->size_power = size_power;
    new_block->id = id;
    new_block->next = NULL;

    if (head == NULL || start < head->start) {
        new_block->next = head;
        head = new_block;
        return;
    }

    Block* cur = head;
    while (cur->next != NULL && cur->next->start < start) {
        cur = cur->next;
    }
    new_block->next = cur->next;
    cur->next = new_block;
}


void remove_block(Block* prev, Block* target) {
    if (prev == NULL) {
        head = target->next;
    } else {
        prev->next = target->next;
    }
    free(target);
}


void allocate(int id, int k, int n) {
    int target_size = 1 << k;

    while (1) {
       
        Block* prev = NULL;
        Block* cur = head;
        while (cur != NULL) {
            if (cur->id == 0 && (1 << cur->size_power) == target_size) {
               
                cur->id = id;
                return;
            }
            prev = cur;
            cur = cur->next;
        }

        
        prev = NULL;
        cur = head;
        while (cur != NULL) {
            if (cur->id == 0 && (1 << cur->size_power) > target_size) {
                
                int new_size_power = cur->size_power - 1;
                int new_start1 = cur->start;
                int new_start2 = cur->start + (1 << new_size_power);

                
                remove_block(prev, cur);

                
                insert_block(new_start1, new_size_power, 0);
                insert_block(new_start2, new_size_power, 0);

                
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }
}


void query() {
    int count = 0;
    Block* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    printf("%d\n", count);

    cur = head;
    while (cur != NULL) {
        printf("%d ", cur->id);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    
    head = (Block*)malloc(sizeof(Block));
    head->start = 0;
    head->size_power = n;
    head->id = 0;
    head->next = NULL;

    for (int i = 0; i < q; i++) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'Q') {
            query();
        } else if (op[0] == 'A') {
            int id, m;
            scanf("%d %d", &id, &m);
            int k = calc_k(m);
            allocate(id, k, n);
        }
    }

    
    return 0;
}