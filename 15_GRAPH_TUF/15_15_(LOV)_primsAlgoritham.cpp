#include <bits/stdc++.h>
using namespace std;

void primsAlgoritham(unordered_map<int, vector<pair<int, int>>> &adj, unordered_map<int, bool> &visited,
                    vector<pair<int, int>> &mstedj, int &mstsum, int Snode) {


    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, Snode, -1}); 

    while (!pq.empty()) {
        int node = pq.top()[1], parent = pq.top()[2], weight = pq.top()[0];
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;

            mstsum += weight;
            if (parent != -1) {
                mstedj.push_back({parent, node});
            }

            for (auto i : adj[node]) {
                if (!visited[i.first]) {
                    pq.push({i.second, i.first, node});
                }
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

    int Snode;
    cout << "Enter the source node: ";
    cin >> Snode;

    unordered_map<int, vector<pair<int, int>>> adj;
    cout << "Enter the edges (format: u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Adjacency list is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " -> { ";
        for (auto &j : adj[i]) {
            cout << "[" << j.first << "," << j.second << "] ";
        }
        cout << "}" << endl;
    }

    unordered_map<int, bool> visited;

    int mstsum = 0;
    vector<pair<int, int>> mstedj;

    primsAlgoritham(adj, visited, mstedj, mstsum, Snode);

    cout << "The edges in the Minimum Spanning Tree (MST) are:" << endl;
    for (auto &edge : mstedj) {
        cout << edge.first << " - " << edge.second << endl;
    }

    cout << "Total path sum is: " << mstsum << endl;

    return 0;
}
