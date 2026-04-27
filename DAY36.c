#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// enqueue
void enqueue(int x) {
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

// dequeue
int dequeue() {
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
    return val;
}

// display
void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // rotation (dequeue + enqueue)
    for (int i = 0; i < m; i++) {
        int val = dequeue();
        enqueue(val);
    }

    display();

    return 0;
}