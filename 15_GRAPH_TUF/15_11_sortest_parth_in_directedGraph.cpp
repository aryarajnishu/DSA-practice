#include <bits/stdc++.h>
using namespace std;

//directed weighted graph

void topology(unordered_map<int, vector<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &stk, int node) {
    visited[node] = true;
    for (auto &i : adj[node]) {
        if (!visited[i.first]) {
            topology(adj, visited, stk, i.first);
        }
    }
    stk.push(node);
}

void shortest_path(unordered_map<int, vector<pair<int, int>>> &adj, stack<int> &stk, int Snode, vector<int> &ans) {
    ans[Snode] = 0;
    while (!stk.empty()) {
        int temp = stk.top();
        stk.pop();
        if (ans[temp] != 1000) {  // Check if node has been reached
            for (auto &i : adj[temp]) {
                if (ans[temp] + i.second < ans[i.first]) {
                    ans[i.first] = ans[temp] + i.second;
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
    
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topology(adj, visited, stk, i);
        }
    }

    stack<int> dummy = stk;
    cout << endl << "Topological Order: ";
    while (!dummy.empty()) {
        cout << dummy.top() << " ";
        dummy.pop();
    }
    cout << endl;

    vector<int> ans(n, 1000);

    shortest_path(adj, stk, Snode, ans);

    cout << "Shortest path distances from node " << Snode << " are: ";
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
