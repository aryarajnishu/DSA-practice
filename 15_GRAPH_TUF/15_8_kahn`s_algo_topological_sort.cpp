#include <bits/stdc++.h>

using namespace std;


vector<int> kahnTopologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0); 
    vector<int> topoOrder;
    
    // Calculate in-degree of each vertex
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            inDegree[j]++;
        }
    }

    // Queue to store vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process the vertices
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topoOrder;
}

int main() {
    int n, m;  // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);  // Adjacency list

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topoOrder = kahnTopologicalSort(n, adj);

    
        for (int v : topoOrder) {
            cout << v << " ";
        }
        cout << endl;

    return 0;
}
