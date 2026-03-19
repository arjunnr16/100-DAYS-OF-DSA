#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, key, count = 0;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = NULL;

        if(head == NULL) head = t;
        else last->next = t;

        last = t;
    }

    scanf("%d", &key);

    while(head) {
        if(head->data == key) count++;
        head = head->next;
    }

    printf("%d", count);
}