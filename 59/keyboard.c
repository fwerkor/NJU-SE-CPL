/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char a[5000000],t[5000000];
int to=0;
bool e[5000000];
int main(){
    int q;
    int last_b=-1,last_s=-1;
    scanf("%d",&q);
    while(q--){
        scanf("%s",t);
        if(t[0]=='?'){
            int k;
            scanf("%d",&k);
            for(int i=0;i<k;i++){
                if(!e[to-1-i]){
                    k++;
                }
            }
            for(int i=0;i<k;i++){
                if(e[to-k+i])printf("%c",a[to-k+i]);
            }
            puts("");
        }else{
            int len=strlen(t);
            for(int i=0;i<len;i++){
                if(t[i]=='M'||t[i]=='m'){
                    if(t[i]=='M'){
                        if(last_b==-1)continue;
                        e[last_b]=0;
                        for(int j=last_b-1;j>=0;j--){
                            if(e[j]&&a[j]<='Z'&&a[j]>='A'){
                                last_b=j;
                                break;
                            }
                        }
                    }
                    if(t[i]=='m'){
                        if(last_s==-1)continue;
                        e[last_s]=0;
                        for(int j=last_s-1;j>=0;j--){
                            if(e[j]&&a[j]<='z'&&a[j]>='a'){
                                last_s=j;
                                break;
                            }
                        }
                    }
                    
                }else{
                    if(t[i]<='Z'&&t[i]>='A'){
                        last_b=to;
                    }
                    if(t[i]<='z'&&t[i]>='a'){
                        last_s=to;
                    }
                    a[to]=t[i];
                    e[to]=1;
                    to++;
                }
            }
        }
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char c;
    int prev;
    int next;
    int last_same;
} Node;

Node* nodes;
int head = -1;
int tail = -1;
int last_upper = -1;
int last_lower = -1;
int len = 0;
int node_count = 0;
int capacity = 0;

void init_nodes(int initial_capacity) {
    capacity = initial_capacity;
    nodes = malloc(capacity * sizeof(Node));
    node_count = 0;
}

void ensure_capacity() {
    if (node_count >= capacity) {
        capacity *= 2;
        nodes = realloc(nodes, capacity * sizeof(Node));
    }
}

void insert_char(char ch) {
    ensure_capacity();
    
    int idx = node_count++;
    nodes[idx] = (Node){ch, tail, -1, -1};
    
    if (tail != -1) {
        nodes[tail].next = idx;
    } else {
        head = idx;
    }
    tail = idx;
    len++;

    if (islower(ch)) {
        nodes[idx].last_same = last_lower;
        last_lower = idx;
    } else {
        nodes[idx].last_same = last_upper;
        last_upper = idx;
    }
}

void delete_node(int idx) {
    Node* node = &nodes[idx];
    
    if (node->prev != -1) {
        nodes[node->prev].next = node->next;
    } else {
        head = node->next;
    }
    
    if (node->next != -1) {
        nodes[node->next].prev = node->prev;
    } else {
        tail = node->prev;
    }

    if (islower(node->c)) {
        last_lower = node->last_same;
    } else {
        last_upper = node->last_same;
    }
    
    len--;
}

void append_string(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == 'm') {
            if (last_lower != -1) {
                delete_node(last_lower);
            }
        } else if (ch == 'M') {
            if (last_upper != -1) {
                delete_node(last_upper);
            }
        } else {
            insert_char(ch);
        }
    }
}

void query(int k) {
    char* result = malloc(k + 1);
    int cur = tail;
    
    for (int i = 0; i < k; i++) {
        result[k - 1 - i] = nodes[cur].c;
        cur = nodes[cur].prev;
    }
    result[k] = '\0';
    
    printf("%s\n", result);
    free(result);
}

int main() {
    init_nodes(1000000);
    
    int n;
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++) {
        char line[1000005];
        fgets(line, sizeof(line), stdin);
        
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        
        if (line[0] == '?') {
            int k;
            sscanf(line + 1, "%d", &k);
            query(k);
        } else {
            append_string(line);
        }
    }
    
    free(nodes);
    return 0;
}