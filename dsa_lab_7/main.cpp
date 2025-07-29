#include <iostream>
using namespace std;

int main() {
    int nNode;
    cout << "Number of nodes: ";
    cin >> nNode;

    int adjMat[nNode][nNode];
    for (int i = 0; i < nNode; i++ ) {
        for (int j = 0; j < nNode; j++) adjMat[i][j] = 0;
    }

    cout << "Enter edges. ( e.g 1 2 )\n";
    for (int i = 0; i < nNode; i++ ) {
        int a, b;
        cout << "Edge #" << i+1 << " : ";
        cin >> a >> b;

        adjMat[a-1][b-1] = 1;
    }


    cout << "Your adj matrix.\n";
    cout << "  | ";
    for (int i = 0; i < nNode; i++ ) cout << i+1 << " ";
    cout << '\n';
    cout << "----------------------------\n";
    for (int i = 0; i < nNode; i++ ) {
        cout << i+1  << " | ";
        for (int j = 0; j < nNode; j++ ) cout << adjMat[i][j] << " ";
        cout << '\n';
    }

    return 0;
}