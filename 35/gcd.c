#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}