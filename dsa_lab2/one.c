#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
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

char pop(){
    if ( curr == 0 ){
        printf("STACK UNDERFLOW\n");
        return '\0';
    }
    return stack[--curr];
}


int main(){
    char* str;
    printf("ENTER A STRING: ");
    scanf("%[^\n]%*c", str);

    int sizeStr = strlen(str);
    
    int tmpInd = 0;
    int i = 0;
    for( i = 0; str[i] != '\0'; i++ ){
        push(str[i]);
    }
    printf("The string is: %s\n", str);
    printf("The string in reverse order is: ");
    while( curr != 0 ){
        char p = pop();
        printf("%c", p);
    }
    printf("\n");

    return 0;
}