#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// insert (keep array sorted)
void insert(int x) {
    int i = size - 1;

    // shift elements to maintain ascending order
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// delete (remove highest priority = smallest element)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    // shift left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
}

// peek
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { // delete
            delete();
        }
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}