#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> &low, vector<int> &disc, int p,
         unordered_map<int, bool> &vis, int &t, vector<int> &aps,
         unordered_map<int, vector<int>> &adj) {

    vis[u] = true;
    disc[u] = low[u] = t++;
    int child = 0;
    bool ap = false;

    for (auto v : adj[u]) {
        if (v == p) continue;

        if (!vis[v]) {
            dfs(v, low, disc, u, vis, t, aps, adj);
            low[u] = min(low[u], low[v]);

            if (low[v] >= disc[u] && p != -1) ap = true;
            child++;
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (p == -1 && child > 1) ap = true;
    if (ap) aps.push_back(u);
}

int main() {
    int n, m;
    cout << "Enter vertices: ";
    cin >> n;
    cout << "Enter edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> vis;
    vector<int> low(n, -1), disc(n, -1), aps;
    int t = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i, low, disc, -1, vis, t, aps, adj);
    }

    cout << "Articulation points:" << endl;
    for (int x : aps) cout << x << " ";
    cout << endl;

    return 0;
}
