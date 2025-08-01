#include <iostream>
#include <queue>
using namespace std;


void secondTask();


void firstTask() {
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
    for ( int i = 0; i < nNode; i++ ) cout << res[i] << " ";
    cout << "\n";

}

int main() {
    // firstTask();
    secondTask();
    return 0;
}