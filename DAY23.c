#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, x;

    // First list
    scanf("%d", &n);
    struct Node *l1 = NULL, *last1 = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;

        if(l1 == NULL) l1 = t;
        else last1->next = t;
        last1 = t;
    }

    // Second list
    scanf("%d", &m);
    struct Node *l2 = NULL, *last2 = NULL;

    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;

        if(l2 == NULL) l2 = t;
        else last2->next = t;
        last2 = t;
    }

    // Merge
    struct Node *res = NULL, *last = NULL;

    while(l1 && l2) {
        struct Node* t;
        if(l1->data < l2->data) {
            t = l1; l1 = l1->next;
        } else {
            t = l2; l2 = l2->next;
        }

        if(res == NULL) res = t;
        else last->next = t;

        last = t;
    }

    if(l1) last->next = l1;
    if(l2) last->next = l2;

    // Print
    while(res) {
        printf("%d ", res->data);
        res = res->next;
    }

    return 0;
}