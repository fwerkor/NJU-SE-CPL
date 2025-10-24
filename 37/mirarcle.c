#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char a[100001];
long long sub[100001], sublen = 0;

long long power(long long n) {
    long long s = 1;
    while (n > 0) {
        n--;
        s *= 10;
    }
    return s;
}

long long re(long long n) {
    long long rev = 0;
    while (n != 0) {
        rev*=10;
        rev+=n%10;
        n /= 10;
    }
    return rev;
}

long long th() {
    double s = 0;
    for (long long i = 0; i < sublen; i++) {
        for (long long j = i; j < sublen; j++) {
            double ss = 0;
            for (long long k = i; k <= j; k++) {
                ss += sub[k] * power(j - k);
            }
            s += ss;
        }
    }
    return s;
}

bool check(char t) {
    if (t <= '9' && t >= '0') return 1;
    return 0;
}

void doit() {
    long long len = strlen(a);
    for (long long i = 0; i < len; i++) {
        if (!check(a[i])) {
            printf("%c", a[i]);
            continue;
        }
        sublen=0;
        long long j = i;
        while (check(a[j + 1]) && j < len) j++;
        for (long long k = i; k <= j; k++) {
            sub[sublen] = a[k] - '0';
            sublen++;
        }
        i=j;
        printf("%lld", re(th()));
    }
    printf("\n");
}

int main() {
    while (scanf("%s", a) != EOF) doit();
    return 0;
}

