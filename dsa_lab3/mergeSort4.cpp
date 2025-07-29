#include <iostream>
#include <cstring>
using namespace std;

// 1 a greater, -1 smaller, 0 equal
int compareStr(char* a, char* b){ 
    int m = strlen(a);
    int n = strlen(b);

    for( int i = 0; i <= m && i <= n; i++ ){
        if( a[i] > b[i] ){
            return 1;
        }
        if( a[i] < b[i] ){
            return -1;
        }
    }
    return 0;
}


struct Result {
    char name[100];
    float cgpa;

    bool isGreaterFrom(Result res){
        if ( compareStr(name, res.name) == 0 ){
            return cgpa > res.cgpa;
        }
        return compareStr(name, res.name) == 1 ? true : false;
    }
};
typedef Result Result;



int main(){

    return 0;
}