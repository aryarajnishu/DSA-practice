#include <bits/stdc++.h>
using namespace std;
// undirected unweighted graph
void BFSofGraph(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, unordered_map<int, int>& parent, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (int i : adj[temp]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = temp;
            }
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

    int x;
    cout << "Enter the node you want to reach: ";
    cin >> x;

    // Adjacency list
    unordered_map<int, vector<int>> adj;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency list is: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> { ";
        for (auto j : adj[i]) {
            cout << j << " ";
        }
        cout << "}" << endl;
    }
    cout << endl;

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    BFSofGraph(adj, visited, parent, 1);

    cout << "Parent array: ";
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;

    vector<int> ans;
    int y = x;
    while (y != -1) {
        ans.push_back(y);
        y = parent[y];
    }

    reverse(ans.begin(), ans.end()); // Reverse the path to get the correct order

    cout << "Shortest path is: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
