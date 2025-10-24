#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    double s = 100000000;
    scanf("%d", &n);
    int a[n + 1];
    a[n] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i + 1] <= a[i]) continue;
        int j = i + 1;
        while (a[j + 1] > a[j] && j < n) j++;
        double i0 = i, j0 = j;
        double ss = (a[j] - a[i]) / (j0 - i0);
        if (ss < s) s = ss;
        i = j;
    }
    if (s == 100000000) {
        printf("0.00\n");
    } else {
        printf("%.2lf\n", s);
    }
    return 0;
}
