#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    k--; 
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pivot = a[k];
    int l = 0, r = n - 1;
    
    while (l < r) {
        while (l < r && a[l] < pivot) {
            l++;
        }
        while (l < r && a[r] >= pivot) {
            r--;
        }
        if (l < r) {
            swap(&a[l], &a[r]);
        }
    }
    swap(&a[l], &a[k]);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}