#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Print first element
    printf("%d ", a[0]);

    // Print only when element changes
    for(i = 1; i < n; i++) {
        if(a[i] != a[i-1])
            printf("%d ", a[i]);
    }

    return 0;
}