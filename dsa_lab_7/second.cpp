#include <iostream>
#include <string>
#include <queue>
using namespace std;


int getIndex(string names[], const string nm) {
    for (int i = 0; i < names->size(); i++){
        if ( names[i] == nm ) return i;
        i++;
    }
    return -1;
}

void secondTask() {
    int nNode, nEdges;
    cout << "Number of nodes: ";
    cin >> nNode;
    string nodeNames[nNode];
    for (int i = 0; i < nNode; i++ ) {
        cout << "Input node no. #" << i+1 << " : ";
        cin >> nodeNames[i];
    }

    int adjMat[nNode][nNode];
    for (int i = 0; i < nNode; i++ ) {
        for (int j = 0; j < nNode; j++) adjMat[i][j] = 0;
    }

    cout << "Number of edges: ";
    cin >> nEdges;

    cout << "Enter edges ( e.g Dhaka Rajshahi ): \n";
    for (int i = 0; i < nEdges; i++ ) {
        string a, b;
        cout << "Edge #" << i+1 << " : ";
        cin >> a >> b;
        const int idxA = getIndex(nodeNames, a);
        const int idxB = getIndex(nodeNames, b);
        if ( idxA == -1 or idxB == -1 ) {
            i--;
            cout << "City name should match with given names.\n";
            continue;
        }
        adjMat[idxA][idxB] = 1;
    }


    cout << "Your adj matrix.\n";
    cout << "    ";
    for (int i = 0; i < nNode; i++ ) cout << i+1 << " ";
    cout << '\n';
    cout << "---------------------\n";
    for (int i = 0; i < nNode; i++ ) {
        cout << i+1  << " | ";
        for (int j = 0; j < nNode; j++ ) cout << adjMat[i][j] << " ";
        cout << '\n';
    }

    int inDegree[nNode], outDegree[nNode];
    for ( int i = 0; i < nNode; i++ ) {
        int sum1 = 0, sum2  = 0;
        for (int j = 0; j < nNode; j++ ) {
            sum2 += adjMat[i][j];
            sum1 += adjMat[j][i];
        }
        inDegree[i] = sum1;
        outDegree[i] = sum2;
    }

    cout << "In Degree:  ";
    for ( int i = 0; i < nNode; i++ ) cout << inDegree[i] << " ";
    cout << "\n";

    cout << "Out Degree: ";
    for ( int i = 0; i < nNode; i++ ) cout << outDegree[i] << " ";
    cout << "\n";


    int res[nNode];
    int idx = 0;
    queue<int> q;
    for ( int i = 0; i < nNode; i++ ) {
        if ( inDegree[i] == 0 ) {
            q.push(i);
            res[idx++] = i+1;
        }
    }

    while ( !q.empty() ) {
        int nd = q.front();
        q.pop();
        for ( int i = 0; i < nNode; i++ ) {
            if ( adjMat[nd][i] > 0 ) {
                adjMat[nd][i]--;
                if ( adjMat[nd][i] == 0 ) {
                    q.push(i);
                    res[idx++] = i + 1;
                }
            }
        }
    }

    cout << "Topological sorted: ";
    for ( int i = 0; i < nNode; i++ ) cout << nodeNames[res[i]] << " ";
    cout << "\n";

}