#include <bits/stdc++.h>
using namespace std;


void BFSofGraph(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);
        for (int i : adj[temp]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
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

    // adjacency list
    unordered_map<int, vector<int>> adj;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);

    }

    cout<<"adjency list is :- "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<i<<" -> { ";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<"}"<<endl;
    }

    unordered_map<int, bool> visited;
   
    vector<int> ans;

    BFSofGraph(adj, visited, ans, 1);

    cout << "BFS of the graph is: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    

    return 0;
}
