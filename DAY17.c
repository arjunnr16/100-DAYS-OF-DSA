#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n], max, min;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = min = a[0];  // initialize both

    for(int i = 1; i < n; i++) {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    printf("Max: %d\nMin: %d", max, min);
    return 0;
}