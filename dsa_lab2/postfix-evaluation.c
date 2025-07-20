#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int curr = 0;
int size = 100;

void push(char str){
    if ( size == curr ){
        printf("ERROR: STACK OVERFLOW\n");
        return;
    }
    stack[curr] = str;
    curr++;
}

int pop(){
    if ( curr == 0 ){
        printf("STACK UNDERFLOW\n");
        return '\0';
    }
    return stack[--curr];
}

int top(){
    if( curr == 0 ){
        printf("Stack is empty.\n");
        return '\0';
    } 
    return stack[curr - 1];
}

int isEmpty(){
    return curr == 0;
}


int mathOperate(char op, int a, int b){
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            printf("ERROR: INVALID OPERATOR\n");
            return 0;
    }
}


int evaluatePostfix(char* str){
    int sz = strlen(str);
    int res = 0;
    for( int i = 0; i < sz; i++ ){
        if ( str[i] == ' ' ) continue;
        if ( str[i] >= '0' && str[i] <= '9' ){
            push(str[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            // printf("a: %d, op: %c, b: %d\n", a, str[i], b);
            res = mathOperate(str[i], a, b);
            push(res);
        }
    }
    return pop();
}


int main(){
    char str[100];
    printf("ENTER A STRING: ");
    // fgets(str, 10, stdin);
    scanf("%[^\n]%*c", str);
    
    printf("The string is: %s\n", str);    
    printf("Answer is: %d\n", evaluatePostfix(str));

    return 0;
}