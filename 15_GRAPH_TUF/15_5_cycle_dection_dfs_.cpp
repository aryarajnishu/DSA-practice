#include <bits/stdc++.h>
using namespace std; 

bool isCyclicDFS(int index, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj, int parent) {
    visited[index] = true;

    for (int i : adj[index]) {
        if (!visited[i]) {
            if (isCyclicDFS(i, visited, adj, index)) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    // adjacency list
    unordered_map<int, vector<int>> adj;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Adding the reverse edge for an undirected graph
    }

    unordered_map<int, bool> visited;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, visited, adj, -1);
            if (ans) {
                cout << "Graph contains cycle" << endl;
                return 0;
            }
        }
    }

    cout << "Graph doesn't contain a cycle" << endl;
    return 0;
}
