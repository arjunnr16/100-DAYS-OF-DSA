#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, x;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    // Create doubly linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        struct Node* t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = NULL;
        t->prev = last;

        if(head == NULL)
            head = t;
        else
            last->next = t;

        last = t;
    }

    // Traverse forward
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}