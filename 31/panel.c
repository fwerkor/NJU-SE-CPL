#include <stdio.h>
#include <string.h>
int main(){
    int W;
    char ID[101],Username[101],Email[101];
    scanf("%d\n%100[^,],%100[^,],%100[^\n]",&W,ID,Username,Email);
    printf("| ID       | %-*.*s |\n| Username | %-*.*s |\n| Email    | %-*.*s |\n",W,W,ID,W,W,Username,W,W,Email);
    return 0;
}

