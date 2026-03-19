#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, key;
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

    scanf("%d", &key);

    // Delete first occurrence
    struct Node *temp = head, *prev = NULL;

    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL)  // first node
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // Print list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}