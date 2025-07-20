#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

char stack[MAX_SIZE], numberStack[MAX_SIZE], temp[20];
int curr = 0, currNum = 0;
int size = 100;

void push(char ch){
    if ( size == curr ){
        printf("ERROR: STACK OVERFLOW\n");
        return;
    }
    stack[curr] = ch;
    curr++;
}

char pop(){
    if ( curr == 0 ){
        printf("STACK UNDERFLOW\n");
        return '\0';
    }
    return stack[--curr];
}

void pushNumber(char str){
    if ( size == currNum ){
        printf("ERROR: STACK OVERFLOW\n");
        return;
    };
    numberStack[currNum] = str;
    currNum++;
}

char popNumber(){
    if ( currNum == 0 ){
        printf("ERROR: STACK UNDERFLOW\n");
        return '\0';
    }
    return numberStack[--currNum];
}


int main(){
    char* str;
    printf("ENTER A STRING: ");
    scanf("%[^\n]%*c", str);

    int sizeStr = strlen(str);
    
    int i = 0;
    for( i = 0; str[i] != '\0'; i++ ){
        push(str[i]);
    }
    printf("The string is: %s\n", str);
    printf("The string in reverse order is: ");

    int sz = 0;
    while( curr != 0 ){
        char p = pop();
        if( !('0' <= p && p <= '9') ){
            for( int i = 0; i < sz; i++ ){
                char pNum = popNumber();
                printf("%c", pNum);
            }
            printf("%c", p);
            sz = 0;
        } else {
            pushNumber(p);
            sz++;
        }
    }
    if ( sz != 0 ){
        for( int i = 0; i < sz; i++ ){
            char pNum = popNumber();
            printf("%c", pNum);
        }
    }
    printf("\n");

    return 0;
}