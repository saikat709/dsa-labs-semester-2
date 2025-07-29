#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node Node;
typedef struct linkedlist LinkedList;

struct node {
    int data;
    Node* next;
};


struct linkedlist {
    Node* head;


    void add(int data){
        Node* newNode;
        newNode->data = data;
        
        if ( head == nullptr ){
            head = newNode;
            return;
        }

        Node* cur = head;
        while( cur->next != NULL ){
            cur = cur->next;
        }
        cur->next = newNode;
    }

    void print(){
        Node* cur = head;
        while( cur != NULL ){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};


int main(){
    Node *a, *b;

    a->data = 10;
    a->next = b;

    LinkedList ll;
    ll.add(10);
    ll.add(20);
    ll.add(29);

    cout << ( a->data ) << endl;

    // ll.print();

    return 0;
}