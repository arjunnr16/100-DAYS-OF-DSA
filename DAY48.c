#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    // If node is a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count in left and right subtree
    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Number of Leaf Nodes: %d\n", countLeaves(root));

    return 0;
}