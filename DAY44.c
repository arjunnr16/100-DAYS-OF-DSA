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

// Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

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
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < N)
                nodes[i]->left = nodes[left];

            if (right < N)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    // Print traversals
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}