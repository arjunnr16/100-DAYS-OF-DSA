#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int main() {
    int N, i;

    scanf("%d", &N);

    // Input queue elements
    for(i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    // Push queue elements into stack
    for(i = 0; i < N; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack to reverse queue
    for(i = 0; i < N; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(i = 0; i < N; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}