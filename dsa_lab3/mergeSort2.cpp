#include <iostream>
#include <cstring>
using namespace std;


bool compareStr(char* a, char* b){  // true if first arr is greater
    int m = strlen(a);
    int n = strlen(b);

    for( int i = 0; i <= m && i <= n; i++ ){
        if( a[i] > b[i] ) return true;
    }

    return false;
}

void copy(char* to, char* from){
    int len = strlen(from);
    for( int i = 0; i < len; i++ ){
        to[i] = from[i];
    }
    to[len] = '\0';
}


void merge(char arr[][100], char temp[][100], int left, int mid, int right){

    for( int i = left; i <= right; i++ ){
        copy(temp[i], arr[i]);
    }

    int i = left, j = mid + 1, k = left;
    while( i <= mid && j <= right ){
        if ( !compareStr(temp[i], temp[j]) ){
            copy(arr[k++], temp[i++]);
        } else {
            copy(arr[k++], temp[j++]);

        }
    }
    while( i <= mid ){
        copy(arr[k++], temp[i++]);
    }

    while( j <= right ){
        copy(arr[k++], temp[j++]);
    }
}


void sort(char arr[][100], char temp[][100], int left, int right){
    if( left < right ){
        int mid = left + (right - left)/2;
        sort(arr,  temp, left, mid);
        sort(arr,  temp, mid+1, right);
        merge(arr, temp, left, mid, right);
    }
}


void mergeSort(char arr[][100], int n){
    char temp[100][100];
    sort(arr, temp, 0, n - 1);
}


int main(){
    char str[] = "hello i am saikat islam a student of software engineering";
    const char delimiter[] = " ";

    char words[100][100];
    int wordCount = 0;

    char* cur = strtok(str, delimiter);

    while (cur != nullptr) {
        copy(words[wordCount++], cur);
        cur = strtok(nullptr, delimiter);
    }

    mergeSort(words, wordCount);

    cout << "sorted words: ";
    for( int i = 0; i < wordCount; i++ ){
        cout << words[i] << " ";
    }
    cout << '\n';
}