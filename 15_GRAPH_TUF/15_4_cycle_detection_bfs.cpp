#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int index, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj, unordered_map<int, int> &parent) {
    queue<int> q;
    q.push(index);
    
    visited[index] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(auto i : adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = temp;
            }
            
            else if(visited[i] && i != parent[temp]){
                return true;
            }
        }
    }

    return false;

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
        adj[v].push_back(u); // Adding the reverse edge for an undirected graph
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    for (int i = 1; i <= n; i++) {  // Loop should go from 1 to n
        if (!visited[i]) {
            bool ans = isCyclic(i, visited, adj, parent);
            if (ans) {
                cout << "Graph contains cycle" << endl;
                return 0;
            }
        }
    }

    cout << "Graph doesn't contain a cycle" << endl;
    return 0;
}
