#include <iostream>
using namespace std;


bool compareChar(char a, char b){
    if ( isupper(a) ) a = tolower(a);
    if ( isupper(b) ) b = tolower(b);
    return a <= b;
}


void merge(char* arr, char* temp, int left, int mid, int right){
    for( int i = left; i <= right; i++ ){
        temp[i] = arr[i];
    }

    int i = left, j = mid + 1, k = left;
    while( i <= mid && j <= right ){
        if ( compareChar(temp[i], temp[j]) ){
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }
    while( i <= mid ){
        arr[k++] = temp[i++];
    }

    while( j <= right ){
        arr[k++] = temp[j++];
    }
}


void sort(char* arr, char* temp, int left, int right){
    if( left < right ){
        int mid = left + (right - left)/2;
        sort(arr,  temp, left, mid);
        sort(arr,  temp, mid+1, right);
        merge(arr, temp, left, mid, right);
    }
}


void mergeSort(char* arr, int n){
    char temp[n];
    sort(arr, temp, 0, n - 2);
}

int main(){
    char arr[] = "AaBd";
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, n);
    cout << "Sorted: " << arr << endl;
    return 0;
}