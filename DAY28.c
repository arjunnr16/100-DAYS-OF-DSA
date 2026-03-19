#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    // Create circular list
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        struct Node* t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = NULL;

        if(head == NULL) {
            head = t;
        } else {
            last->next = t;
        }
        last = t;
    }

    // Make it circular
    if(last != NULL)
        last->next = head;

    // Traverse
    struct Node* temp = head;
    if(temp != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}