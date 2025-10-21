#include <stdio.h>
#include <string.h>

static char *ones[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(){
    int n;
    scanf("%d",&n);
    if(n<=19) printf("%s\n",ones[n]);
    if(n>=20 && n<=99 && n%10!=0) printf("%s-%s\n",tens[n/10],ones[n%10]);
    if(n>=20 && n<=99 && n%10==0) printf("%s\n",tens[n/10]);
    if(n>=100 && n%100==0) printf("%s hundred\n",ones[n/100]);
    if(n>=100 && n%100!=0 && n%100<=19) printf("%s hundred and %s\n",ones[n/100],ones[n%100]);
    if(n>=100 && n%100!=0 && n%100>20 && n%10==0) printf("%s hundred and %s\n",ones[n/100],tens[n/10%10]);
    if(n>=100 && n%100!=0 && n%100>20 && n%10!=0 && n/10%10!=0) printf("%s hundred and %s-%s\n",ones[n/100],tens[n/10%10],ones[n%10]);
    
    
    return 0;
}