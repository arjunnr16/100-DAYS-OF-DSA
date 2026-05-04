#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for BFS
struct Node* queue[MAX];
int front = -1, rear = -1;

// Queue functions
void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

// Example usage
int main() {
    // Creating a sample tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}