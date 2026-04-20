          #include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Print nodes in range
void printInRange(struct node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        printInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        printInRange(root->right, low, high);
}

// Main
int main() {
printf("Devarsh Gupta \nPRN = 25070521139 \nSEC = C1\n");
    // -------- Example 1 --------
    struct node* root1 = NULL;

    root1 = insert(root1, 17);
    root1 = insert(root1, 4);
    root1 = insert(root1, 18);
    root1 = insert(root1, 2);
    root1 = insert(root1, 9);

    printf("Example 1 Output: ");
    printInRange(root1, 4, 24);


    // -------- Example 2 --------
    struct node* root2 = NULL;

    root2 = insert(root2, 16);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 1);
    root2 = insert(root2, 10);

    printf("\nExample 2 Output: ");
    printInRange(root2, 13, 23);

    return 0;
}


 
