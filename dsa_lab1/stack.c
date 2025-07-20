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
    int size, current_size;
    printf("Size of the stack: ");

    scanf("%d", &size);
    int stack[size];
    current_size = 0;
    push(stack, size, &current_size, 10 );
    push(stack, size, &current_size, 17 );
    push(stack, size, &current_size, 14 );
    push(stack, size, &current_size, 22 );

    int a;
    a = top(stack, size, &current_size);
    printf("TOP: %d\n", a);

    a = pop(stack, size, &current_size);
    printf("EL: %d\n", a);
    a = pop(stack, size, &current_size);
    printf("EL: %d\n", a);
    a = pop(stack, size, &current_size);
    printf("EL: %d\n", a);
    a = pop(stack, size, &current_size);
    printf("EL: %d\n", a);

    return 0;
}