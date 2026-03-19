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

    // Traverse
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}