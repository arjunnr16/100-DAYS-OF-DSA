#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, count = 0;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    // Create list
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            last->next = newNode;

        last = newNode;
    }

    // Count nodes
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}