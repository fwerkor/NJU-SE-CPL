#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int pivot = a[k - 1];
    int l = 0, r = n - 1;
    
    swap(&a[k - 1], &a[n - 1]);
    r = n - 2; 
    
    while (l <= r) {
        while (l <= r && a[l] < pivot) l++;
        while (l <= r && a[r] > pivot) r--;
        if (l <= r) {
            swap(&a[l], &a[r]);
            l++;
            r--;
        }
    }
    
    swap(&a[l], &a[n - 1]);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}