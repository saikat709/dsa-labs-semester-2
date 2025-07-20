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
    int stack[size], choice = 1;
    current_size = 0;

    printf("1. Add to stack\n");
    printf("2. Pop from stack\n");
    printf("3. Top of the stack\n");
    printf("User -1 to exit\n\n");

    while( 1 ){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if ( choice == -1 ){
            break;
        } else if( choice == 1 ){
            int num_el = 0;
            printf("How many elements do you want to add? ");
            scanf("%d", &num_el);
            for( int i = 0; i < num_el; i++ ){
                int num = 0;
                printf("PLEASE ENTER NUMBER (%d of %d): ", i+1, num_el);
                scanf("%d", &num);
                push(stack, size, &current_size, num );
            }
        } else if ( choice == 2 ) {
            int a = pop(stack, size, &current_size);
            printf("Poped element: %d\n", a);
        } else if ( choice == 3 ) {
            int a = top(stack, size, &current_size);
            printf("TOP: %d\n", a);
        }

    }

    return 0;
}