#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// push
void push(char x) {
    stack[++top] = x;
}

// pop
char pop() {
    return stack[top--];
}

// precedence
int prec(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int k = 0;

    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // operand
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // right parenthesis
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // operator
        else {
            while (top != -1 && prec(stack[top]) >= prec(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // pop remaining
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}