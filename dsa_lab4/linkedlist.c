#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node* next; 
};


Node* createNode(int data){
    Node* node = malloc(sizeof(Node*));
    if( node == NULL ){
        return NULL;
    }
    node->data = data;
    return node;
}


void insert(int d, Node* head){
    Node* newNode = createNode(d);

    Node* cur = head;

    if( cur->next == NULL ){
        cur->next = newNode;
        return;
    }
    
    while( cur->next != NULL ){
        cur = cur->next;
    }
    cur->next = newNode;
}


void printLinked(Node* head){
    Node* cur = head;
    while( cur != NULL ){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


int main(){
    Node* head = createNode(10);
    insert(19,   head );
    insert(45,   head );
    insert(3,    head );
    insert(2,    head );
    insert(2,    head );
    insert(99,   head );
    printLinked( head );
}