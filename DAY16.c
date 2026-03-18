#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++) {
        int count = 1;
        if(a[i] == -1) continue;  // already counted

        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                a[j] = -1;  // mark duplicate
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}