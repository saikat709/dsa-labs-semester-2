#include <iostream>
#include <string>
#define MAX_SIZE 100;
using namespace std;

struct StackStruct {
    string parts[100];
    int size = 0;
    int currentSize = 0;

    void setSize(int s){
        size = s;
    };

    string pop(){
        if ( size == 0 ){
            cout << "SATCK UNDERFLOW: " << endl;
        }
        return parts[--currentSize];
    };

    void push(string str){
        if ( size == currentSize ){
            cout << "ERROR: STACK OVERFLOW " << endl;
            return;
        }
        parts[currentSize] = str;
        currentSize++;
    };

    string top(){
        if( size == 0 ){
            cout << "Stack is empty." << endl;
            return "-1";
        } 
        return parts[currentSize - 1];
    };
};
typedef StackStruct Stack;


int main(){
    cout << "ENTER A STRING: ";
    string abc; cin >> abc;
    cout << "The string is: " << abc << endl;
    Stack stack;
    stack.setSize(20);

    string as = "HELLO";
    stack.push(as);
    string p = stack.pop();

    return 0;
}