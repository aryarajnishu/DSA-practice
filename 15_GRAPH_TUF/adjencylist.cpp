
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void BFSofGraph(unordered_map<int, bool> &visited, vector<int> &ans, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            ans.push_back(temp);
            for (auto i : adj[temp]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << endl;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << endl;

    Graph g;
    int direction = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, direction);
    }

    g.printGraph();

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vector<int> ans;
    g.BFSofGraph(visited, ans, 1); // Assuming the BFS starts from node 1

    cout << "BFS of graph is: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
