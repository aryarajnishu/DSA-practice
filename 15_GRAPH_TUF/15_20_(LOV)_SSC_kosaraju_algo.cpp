#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v, adj, vis, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &tr, vector<bool> &vis, vector<int> &comp) {
    vis[u] = true;
    comp.push_back(u);
    for (int v : tr[u]) {
        if (!vis[v]) dfs2(v, tr, vis, comp);
    }
}

int main() {
    int n = 5;  // number of vertices
    vector<vector<int>> adj(n), tr(n);

    // 🔹 Inbuilt directed graph (example)
    // Graph edges:
    // 0 → 2, 0 → 3
    // 1 → 0
    // 2 → 1
    // 3 → 4
    adj[0] = {2, 3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};
    // adj[4] = {};  // no outgoing edge

    // Build transpose graph
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            tr[v].push_back(u);
        }
    }

    // Step 1: Order by finish time
    stack<int> st;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i, adj, vis, st);
    }
    for(int i=0 ; i<n ; i++){
        vis[i] = false;
    }

    // Step 2: DFS on transpose
    cout << "Strongly Connected Components:" << endl;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!vis[u]) {
            vector<int> comp;
            dfs2(u, tr, vis, comp);
            for (int x : comp) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}
