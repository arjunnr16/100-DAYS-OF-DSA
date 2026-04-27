#include <stdio.h>

int main() {
    int stack[100], top = -1;
    int n, m;

    // number of elements to push
    scanf("%d", &n);

    // push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // number of pops
    scanf("%d", &m);

    // pop m elements
    for (int i = 0; i < m; i++) {
        if (top == -1) {
            break; // avoid underflow
        }
        top--;
    }

    // display remaining stack (top to bottom)
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}