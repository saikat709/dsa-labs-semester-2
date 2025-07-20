#include <stdio.h>

void push(int * st, int sz, int * pos, int value){
    if ( *pos == sz ){
        printf("STACK OVERFLOW: Can not add more.\n");
        return;
    }
    st[(*pos)] = value;
    *pos += 1;
}

int pop(int * st, int sz, int * pos ){
    if( *pos == 0 ){
        printf("STACK UNDERFLOW: Can not add more.\n");
        return 0;
    } else {
        return st[--(*pos)];
    }
}

int top( int * st, int sz, int * pos ){
    return st[(*pos)-1];
}

int main(){
    int size = 10, current_size;
    int stack[size], choice = 1;
    current_size = 0;

    char brackets[] = "madam";

    for( int i = 0; i < 6; i++ ){
        push(stack, size, &current_size, brackets[i]);
    }

    int isPalin = 1;
    for( int i = 0; i < 5; i++ ){
        char fromLast = pop(stack, size, &current_size );
        if ( fromLast != brackets[i] ){
            isPalin = 0;
        }
    }

    if ( isPalin ){
        printf("YES!!!\n");
    } else {
        printf("NO...\n");
    }

    return 0;
}