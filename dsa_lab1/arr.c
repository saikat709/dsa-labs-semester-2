#include <stdio.h>
#define SIZE 10

int arr[SIZE]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


int main() {
    int i = 0;
    int mid = SIZE/2;

    printf("PRINTING ARRAY: ");
    for( i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Removing middle element at: %d\n", mid);

    for( i = mid; i < SIZE; i++){
       arr[i-1] = arr[i];
       arr[i]   = 0;
    }
 
    printf("AFTER DELETE:   ");
    for( i = 0; i < SIZE - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("INSERTING at middle element: %d\n", mid);
    int prev = 29;                   // new value;
    for( i = mid - 1; i < SIZE; i++){
        int temp = arr[i];
        arr[i] = prev;
        prev = temp;
    }

    printf("AFTER INSERT:   ");
    for( i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
