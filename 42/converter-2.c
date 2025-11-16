#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};
void lite(long long n){
    if(n<=19) printf("%s",ones[n]);
    if(n>=20 && n<=99 && n%10!=0) printf("%s-%s",tens[n/10],ones[n%10]);
    if(n>=20 && n<=99 && n%10==0) printf("%s",tens[n/10]);
    if(n>=100 && n%100==0) printf("%s hundred",ones[n/100]);
    if(n>=100 && n%100!=0 && n%100<=19) printf("%s hundred and %s",ones[n/100],ones[n%100]);
    if(n>=100 && n%100!=0 && n%100>=20 && n%10==0) printf("%s hundred and %s",ones[n/100],tens[n/10%10]);
    if(n>=100 && n%100!=0 && n%100>=20 && n%10!=0) printf("%s hundred and %s-%s",ones[n/100],tens[n/10%10],ones[n%10]);
}
int doit(long long n){
    if(n==0){
        printf("zero\n");
        return 0;
    }
    if(n<0){
        printf("minus ");
        n=-n;
    }
    if(n>=1000000000){
        lite(n/1000000000);
        printf(" billion ");
    }
    n%=1000000000;
    if(n>=1000000){
        lite(n/1000000);
        printf(" million ");
    }
    n%=1000000;
    if(n>=1000){
        lite(n/1000);
        printf(" thousand ");
    }
    n%=1000;
    if(n>=1) lite(n);
    printf("\n");
    return 0;
}
int main(){
    long long n;
    scanf("%lld",&n);
    doit(n);
    return 0;
}
