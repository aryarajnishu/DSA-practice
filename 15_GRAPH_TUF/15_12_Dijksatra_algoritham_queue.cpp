#include <bits/stdc++.h>
using namespace std;

void sortpart(unordered_map<int, vector<pair<int, int>>> adj , vector<int> &dis , int x){

    // makeing priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
    mh.push({0, x});
    dis[x]=0;

    while(!mh.empty()){
        int node = mh.top().second;
        int weight = mh.top().first;

        mh.pop();

        for(auto i : adj[node]){
            if(weight + i.second < dis[i.first]){
                dis[i.first] = weight + i.second; 
                mh.push({dis[i.first] , i.first});
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

    

    vector<int> dis(n , INT_MAX);

    sortpart(adj , dis , Snode);
    cout<<"ans is :- ";
    for(int i=0 ; i<n ; i++){
        cout<<dis[i]<<" ";
    }

    return 0;
}
