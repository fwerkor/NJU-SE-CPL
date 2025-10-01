#include <stdio.h>
#include <string.h>
int main(){
    long long addr,data;
    scanf("%lld %lld",&addr,&data);
    printf("0x%08x:  %02x %02x %02x %02x\n",addr,data/256/256/256,data/256/256%256,data/256%256,data%256);
    return 0;
}