#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0)
        return 0;

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Array of node pointers
    struct Node* nodes[N];

    // Create nodes
    for (int i = 0; i < N; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    // Connect children
    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < N)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < N)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    // Root is first node
    struct Node* root = nodes[0];

    // Print inorder traversal
    inorder(root);

    return 0;
}