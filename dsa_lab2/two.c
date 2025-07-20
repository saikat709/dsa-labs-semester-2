#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

char stack[MAX_SIZE][20], temp[20];
int curr = 0;
int size = 100;

void push(char* str){
    if ( size == curr ){
        printf("ERROR: STACK OVERFLOW\n");
        return;
    }
    strcpy(stack[curr], str);
    curr++;
}

char * pop(){
    if ( curr == 0 ){
        printf("STACK UNDERFLOW\n");
        return NULL;
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
        if ( str[i] == ' ' ){
            temp[tmpInd] = '\0';
            push(temp);
            tmpInd = 0;
            temp[0] = '\0';
        } else {
            temp[tmpInd++] = str[i];
        }
    }
    temp[tmpInd++] = str[i];
    push(temp);
    printf("The string is: %s\n", str);
    

    while( curr != 0 ){
        char* p = pop();
        printf("%s ", p);
    }
    printf("\n");

    return 0;
}