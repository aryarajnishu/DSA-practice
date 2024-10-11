#include <bits/stdc++.h>
using namespace std;

void sortpart(unordered_map<int, vector<pair<int, int>>> &adj , vector<int> &dis , int x){
    set<pair<int, int>> mh;  // Set to maintain minimum distances
    mh.insert({0, x});
    dis[x] = 0;

    while(!mh.empty()){
        int node = mh.begin()->second;
        int weight = mh.begin()->first;
        mh.erase(mh.begin());

        for(auto &i : adj[node]){
            if(weight + i.second < dis[i.first]){
                // If there's already a better distance found, remove the old one
                if (dis[i.first] != INT_MAX) {
                    mh.erase(mh.find({dis[i.first], i.first}));
                }
                
                // Update the distance
                dis[i.first] = weight + i.second;
                
                // Insert the updated distance in the set
                mh.insert({dis[i.first], i.first});
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

    vector<int> dis(n, INT_MAX);

    sortpart(adj, dis, Snode);

    cout << "Shortest distances from source node " << Snode << " are: ";
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
