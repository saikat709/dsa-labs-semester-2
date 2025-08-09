#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode Node;

struct BSTNode {
    int   data;
    Node *left;
    Node *right;
    Node *parent;
};

Node* createNode(const int data) {
    Node* node = malloc(sizeof(Node));

    if ( node == NULL ) {
        printf("Not enough memory for node\n");
        return NULL;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

void printInOrder(const Node *root) {
    if (root == NULL) return;

    if ( root->left != NULL ) printInOrder(root->left);
    printf("%d ", root->data);
    if ( root -> right != NULL ) printInOrder(root->right);
}

Node* insertToBST(Node *root, const int data) {
    Node* node = createNode(data);

    if ( root == NULL ) {
        root = node;
        return root;
    }

    Node* prev = NULL;
    Node* curr = root;

    while ( curr != NULL ) {
        prev = curr;
        if ( curr->data < data ) curr = curr->right;
        else curr = curr->left;
    }

    if ( prev == NULL ) {
        root->parent = node;
        root = node;
    } else {
        if ( node->data < prev->data ) prev->left = node;
        else prev->right = node;
        node->parent = prev;
    }

    return root;
}

Node* bstMinimum(Node* root) {
    Node* curr = root;
    if ( root == NULL ) return NULL;

    while ( curr->left != NULL ) {
        curr = curr->left;
    }

    return curr;
}

Node* findSuccessor(Node* root) {
    if ( root == NULL ) return NULL;

    if ( root->right != NULL ) return bstMinimum(root);

    Node* curr = root;
    Node* par = root->parent;
    while ( par->parent != NULL && curr != par->left ) {
        curr = par;
        par = par->parent;
    }
    return par;
}

Node* searchInBst(Node* root, const int key) {
    if ( root == NULL ) return root;
    Node* curr = root;
    while ( curr != NULL && key != curr->data ) {
        if ( key < curr->data ) curr = curr->left;
        else curr = curr->right;
    }

    return curr;
}

int deleteFromBST(Node* root, const int data) {
    if ( root == NULL ) return 0;
    Node* dataNode = searchInBst(root, data);

    if ( root->left != NULL && root->right != NULL ) {
        Node* successor = findSuccessor(dataNode);
        dataNode->data = successor->data;
        successor->data = data;
        deleteFromBST(root, data);
    } else {
        Node* parent = dataNode->parent;
        if ( parent->left == dataNode ) {
            if ( dataNode->left != NULL ) parent->left = dataNode->left;
            else parent->left = dataNode->right;
        } else {
            if ( dataNode->left != NULL ) parent->right = dataNode->left;
            else parent->right = dataNode->right;
        }
    }

    return 1;
}

int deleteFromBST2(Node* root, const int data) {
    Node* x = NULL;
    Node* y = NULL;
    Node* z = searchInBst(root, data);

    if ( z == NULL ) {
        printf("Data not found.");
        return -1;
    }
    if ( z->left == NULL || z->right == NULL ) y = z;
    else y = findSuccessor(z);

    if ( y->left != NULL ) x = y->left;
    else x = y->right;

    if ( x != NULL ) x->parent = y->parent;

    if ( y->parent == NULL ) {
        root = x;
    } else {
        if ( y == y->parent->left ) y->parent->left = x;
        else y->parent->right = x;
    }

    if ( y != z ) z->data = y->data;
    return 1;
}

int main() {
    printf("How many nodes do you have: ");
    int nNodes;
    scanf("%d", &nNodes);
    Node *root = NULL;

    for ( int i = 0; i < nNodes; i++ ) {
        printf("Enter node #%d: ", i+1);
        int data; scanf("%d", &data);
        root = insertToBST(root, data);
    }

    printf("Inserted successfully. \nBST: ");

    printInOrder(root);
    printf("\n");

    printf("Search a node by data. Enter value: ");
    int key;
    scanf("%d", &key);
    Node* searched = searchInBst(root, key);
    if ( searched == NULL ) printf("Not found.\n");
    else printf("Key found in the BST.\n");

    printf("Delete a node by data. Enter value: ");
    int deleteKey;
    scanf("%d", &deleteKey);
    int deleted = deleteFromBST2(root, deleteKey);
    if ( searched == NULL ) printf("Could not delete.\nBST: ");
    else printf("Deleted Node from BST.\nBST: ");

    printInOrder(root);

    return 0;
}
