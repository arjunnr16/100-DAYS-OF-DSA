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

    // Compare values (simple method)
    while(l1) {
        struct Node* temp = l2;
        while(temp) {
            if(l1->data == temp->data) {
                printf("%d", l1->data);
                return 0;
            }
            temp = temp->next;
        }
        l1 = l1->next;
    }

    printf("No Intersection");
}