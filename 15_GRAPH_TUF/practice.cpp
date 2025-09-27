#include <bits/stdc++.h>
using namespace std;

void primsAlgoritham(unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &vis,
                    vector<pair<int, int>> &mstedj, int &mstsum, int Snode) {


    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, Snode, -1}); 

    while (!pq.empty()) {
        int node = pq.top()[1], parent = pq.top()[2], weight = pq.top()[0];
        pq.pop();

        if (!vis[node]) {
            vis[node] = true;

            mstsum += weight;
            if (vis[node] != 0) {
                mstedj.push_back({parent, node});
            }

            for (auto i : adj[node]) {
                if (!vis[i.first]) {
                    pq.push({i.second, i.first, node});
                }
            }
        }
    }
}

int main() {
    int n = 5; // number of vertices
    int m = 7; // number of edges
    int Snode = 0; // source node

    vector<tuple<int,int,int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 8},
        {2, 4, 10},
        {3, 4, 2}
    };


    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &e : edges) {
        int u, v, w;
        tie(u, v, w) = e;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Adjacency list is:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> { ";
        for (auto &j : adj[i]) {
            cout << "[" << j.first << "," << j.second << "] ";
        }
        cout << "}\n";
    }


    vector<int> vis(n+1,0);

    int mstsum = 0;
    vector<pair<int, int>> mstedj;

    primsAlgoritham(adj, vis, mstedj, mstsum, Snode);

    cout << "The edges in the Minimum Spanning Tree (MST) are:" << endl;
    for (auto &edge : mstedj) {
        cout << edge.first << " - " << edge.second << endl;
    }

    cout << "Total path sum is: " << mstsum << endl;

    return 0;
}
