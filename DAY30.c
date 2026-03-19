#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef, exp;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *last = NULL;

    // Create polynomial
    for(int i = 0; i < n; i++) {
        struct Node* t = malloc(sizeof(struct Node));
        scanf("%d %d", &t->coef, &t->exp);
        t->next = NULL;

        if(head == NULL) head = t;
        else last->next = t;

        last = t;
    }

    // Print polynomial
    struct Node* temp = head;
    while(temp) {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}