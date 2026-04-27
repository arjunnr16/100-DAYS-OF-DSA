#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// check empty
int isEmpty() {
    return front == -1;
}

// check full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// push front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    dq[front] = x;
}

// push back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    dq[rear] = x;
}

// pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            if (isEmpty()) printf("-1\n");
            else printf("%d\n", dq[front]);
        }
        else if (op[0] == 'b') { // back
            if (isEmpty()) printf("-1\n");
            else printf("%d\n", dq[rear]);
        }
        else if (op[0] == 's') { // size
            if (isEmpty()) printf("0\n");
            else if (rear >= front)
                printf("%d\n", rear - front + 1);
            else
                printf("%d\n", MAX - front + rear + 1);
        }
        else if (op[0] == 'e') { // empty
            printf("%d\n", isEmpty());
        }
    }

    // final state
    display();

    return 0;
}