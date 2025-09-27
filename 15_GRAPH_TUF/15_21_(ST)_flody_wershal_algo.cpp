#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // a large value to represent infinity

int main() {
    int n = 6; // number of vertices

    // 🔹 Inbuilt graph (Adjacency Matrix form)
    // Graph:
    // 0 → 1 (7), 0 → 2 (9), 0 → 5 (14)
    // 1 → 2 (10), 1 → 3 (15)
    // 2 → 3 (11), 2 → 5 (2)
    // 3 → 4 (6)
    // 4 → 5 (9)

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // initialize diagonal as 0
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    // edges
    dist[0][1] = 7;
    dist[0][2] = 9;
    dist[0][5] = 14;
    dist[1][2] = 10;
    dist[1][3] = 15;
    dist[2][3] = 11;
    dist[2][5] = 2;
    dist[3][4] = 6;
    dist[4][5] = 9;

    // 🔹 Floyd–Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 🔹 Print shortest distance matrix
    cout << "All-Pairs Shortest Path (Floyd–Warshall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << setw(3) << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
