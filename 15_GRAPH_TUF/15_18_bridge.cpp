#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &low, vector<int> &dis, int parent,
         unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, 
         int &timmer, vector<vector<int>> &result) {
    visited[node] = true;

    low[node] = dis[node] = timmer++;

    for (auto nbh : adj[node]) {
        if (nbh == parent) {
            continue;
        }
        if (!visited[nbh]) {
            dfs(nbh, low, dis, node, adj, visited, timmer, result);
            low[node] = min(low[node], low[nbh]);

            // Check if the edge is a bridge
            if (low[nbh] > dis[node]) {
                result.push_back({node, nbh});
            }
        } else {
            // Back edge
            low[node] = min(low[node], dis[nbh]);
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

    unordered_map<int, vector<int>> adj;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<int> low(n, -1);
    vector<int> dis(n, -1);
    int timmer = 0;

    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, low, dis, -1, adj, visited, timmer, result);
        }
    }

    cout << "Bridges in the graph are:" << endl;
    for (auto &bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
