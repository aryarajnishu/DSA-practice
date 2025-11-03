#include <bits/stdc++.h>
using namespace std;

void dfs1(unordered_map<int, vector<int>> &adj, stack<int> &stk, unordered_map<int, bool> &visited, int node) {
    visited[node] = true;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs1(adj, stk, visited, i);
        }
    }
    stk.push(node);
}

void dfs2(unordered_map<int, vector<int>> &transpose, unordered_map<int, bool> &visited, int node, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);
    for (auto i : transpose[node]) {
        if (!visited[i]) {
            dfs2(transpose, visited, i, component);
        }
    }
}

int main() {
    unordered_map<int, vector<int>> adj;
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {5, 6};
    adj[5] = {6};
    adj[6] = {4, 7};
    adj[7] = {};

    cout << "Original Adjacency list:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " -> { ";
        for (auto &j : adj[i]) cout << j << " ";
        cout << "}" << endl;
    }

    // Step 1: Topological ordering (store in stack)
    stack<int> stk;
    unordered_map<int, bool> visited;
    for (int i = 0; i < 8; i++) {
        if (!visited[i]) {
            dfs1(adj, stk, visited, i);
        }
    }

    // Step 2: Transpose the graph
    unordered_map<int, vector<int>> transpose;
    for (int i = 0; i < 8; i++) {
        for (auto j : adj[i]) {
            transpose[j].push_back(i);
        }
    }

    cout << "\nTransposed Adjacency list:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " -> { ";
        for (auto &j : transpose[i]) cout << j << " ";
        cout << "}" << endl;
    }

    // Step 3: DFS on transposed graph using stack order
    for (auto &p : visited) p.second = false;

    cout << "\nStrongly Connected Components (SCCs):" << endl;
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(transpose, visited, node, component);

            // print one SCC
            for (auto x : component) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}
