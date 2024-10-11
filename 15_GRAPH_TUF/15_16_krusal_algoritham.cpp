#include <bits/stdc++.h>
using namespace std;

// Function to initialize disjoint sets
void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 1; i <= n; i++) {  // 1-based indexing
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find function with path compression
int find_parent(vector<int> &parent, int n) {
    if (parent[n] == n) {
        return n;
    }
    return parent[n] = find_parent(parent, parent[n]);
}

// Union function with rank optimization
void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = find_parent(parent, u);
    v = find_parent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal's algorithm to find Minimum Spanning Tree (MST)
void kruskal(int n, vector<vector<int>> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1);  // 1-based indexing
    vector<int> rank(n + 1);    // 1-based indexing
    makeset(parent, rank, n);   // Initialize sets

    int minWeight = 0;
    vector<pair<int, int>> mst; // To store edges of MST

    for (auto &edge : edges) {
        int wt = edge[0];  // weight of the edge
        int u = edge[1];   // first vertex of the edge
        int v = edge[2];   // second vertex of the edge

        // Find parent of u and v
        int parent_u = find_parent(parent, u);
        int parent_v = find_parent(parent, v);

        // If they belong to different sets, take the edge
        if (parent_u != parent_v) {
            minWeight += wt;
            mst.push_back({u, v});  // Add this edge to MST
            unionset(parent_u, parent_v, parent, rank);  // Union the sets
        }
    }

    // Output the MST and its total weight
    cout << "Edges in the MST:\n";
    for (auto &edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }
    cout << "Total weight of the MST: " << minWeight << endl;
}

int main() {
    int n = 7;  // Number of nodes (1-based, so nodes are from 1 to 7)
    vector<vector<int>> edges = {
        {2, 1, 2},  // {weight, u, v}
        {1, 1, 4},
        {4, 1, 5},
        {9, 4, 5},
        {5, 4, 3},
        {3, 2, 4},
        {3, 2, 3},
        {2, 6, 7},
        {8, 3, 6}
    };

    kruskal(n, edges);  // Call Kruskal's algorithm
    return 0;
}
