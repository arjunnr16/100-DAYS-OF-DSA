#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, x;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    // Create list
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = NULL;

        if(head == NULL) head = t;
        else last->next = t;

        last = t;
    }

    scanf("%d", &k);
    k = k % n;

    // Find (n-k)th node
    struct Node *temp = head;
    for(int i = 1; i < n - k; i++)
        temp = temp->next;

    // Make circular
    last->next = head;

    // Change head
    head = temp->next;
    temp->next = NULL;

    // Print
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}