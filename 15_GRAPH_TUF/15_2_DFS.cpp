#include <bits/stdc++.h>
using namespace std;

void DFSofGraph(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, vector<int> &ans, int node) {
    ans.push_back(node);
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            DFSofGraph(adj, visited, ans, i);
        }
    }
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
    }

    unordered_map<int, bool> visited;
    // Initialize visited map for all nodes
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFSofGraph(adj, visited, ans, i);
        }
    }


    cout << "DFS traversal is: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
