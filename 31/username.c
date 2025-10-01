#include <stdio.h>
#include <string.h>
int main(){
    char username[101];
    scanf("%[^\n]",username);
    printf("%d\n\"%.20s\"\n",strlen(username),username);
    return 0;
}