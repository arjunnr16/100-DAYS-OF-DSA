#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// push
void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// pop
int pop() {
    if (top == NULL) {
        return -1; // underflow
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char expr[100];
    int i = 0;

    // read full line (with spaces)
    fgets(expr, sizeof(expr), stdin);

    while (expr[i] != '\0') {

        // skip spaces and newline
        if (expr[i] == ' ' || expr[i] == '\n') {
            i++;
            continue;
        }

        // if operand (single digit)
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        }
        // operator
        else {
            int b = pop();
            int a = pop();

            if (a == -1 || b == -1) {
                printf("Invalid Expression");
                return 0;
            }

            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    // final result
    int result = pop();

    if (top != NULL) {
        printf("Invalid Expression");
    } else {
        printf("%d", result);
    }

    return 0;
}