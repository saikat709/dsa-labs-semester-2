#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

Node* head;
int alreadyUsed[57] = {0};

struct Node {
    int roll;
    char name[50];
    Node* next;
};


Node* createNode(int roll, char* name) {
    
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}



void removeDucplicate1(){

    if ( head->next == NULL ){
        return;
    }

    Node* curr = head->next;
    Node* prev = head;

    alreadyUsed[head->roll]++;

    while( curr != NULL ) {
        alreadyUsed[curr->roll]++;

        if( alreadyUsed[curr -> roll] > 1 ) prev -> next = curr -> next;
        else  prev = curr;

        if ( curr -> next != NULL ) curr = curr -> next;
        else break;
    }
    
}



void removeDucplicate(){

    if ( head->next == NULL ){
        return;
    }

    Node* curr = head->next;
    Node* prev = createNode(head->roll, head->name);
    Node* newHead = prev;

    alreadyUsed[head->roll]++;

    while( curr != NULL ) {
        alreadyUsed[curr->roll]++;

        // printf("Used: roll: %d,   cnt: %d\n", curr->roll,  alreadyUsed[curr->roll]);
        
        if( alreadyUsed[curr->roll] == 1 ){
            prev->next = createNode( curr->roll, curr->name);
            prev = prev->next;

            // printf("added roll: %d\n", curr->roll);
        }  else {
            // printf("SKipped roll: %d, cnt: %d\n", curr->roll, alreadyUsed[curr->roll]);
        }

        if ( curr->next != NULL ) curr = curr->next;
        else break;
    }

    
    head = newHead;
}

void printLinkedList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}


void addNode(int roll, char* name) {
    Node* newNode = createNode(roll, name);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



int main(){
    head = NULL;

    for( int i = 0; i < 57; i++ ) alreadyUsed[i] = 0;

    printf("How many nodes do you want to add? ");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int roll;
        char name[50];

        printf("\nEnter roll number: ");
        scanf("%d", &roll);
        printf("Enter name: ");
        scanf("%s", name);
        
        addNode(roll, name);
    }

    printf("Adding completed.\n\n");

    printf("Your linked list: \n");
    printLinkedList();

    printf("\nRemoving duplicate element.\n\n");
    removeDucplicate1();

    printLinkedList();

    return 0;
}