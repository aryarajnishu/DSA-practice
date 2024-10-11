#include<bits/stdc++.h>
using namespace std;

void dfs1(unordered_map<int, vector<int>> &adj , stack<int> stk , unordered_map<int, bool> &visited , int node){
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs1(adj , stk , visited , i);
        }
    }
    stk.push(node);
}


int main(){
    // int n;
    // cout << "Enter the number of vertices: ";
    // cin >> n;

    // int m;
    // cout << "Enter the number of edges: ";
    // cin >> m;

    // unordered_map<int, vector<int>> adj;
    // cout << "Enter the edges (format: u v):" << endl;
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;

    //     adj[u].push_back(v);
    // }

    unordered_map<int, vector<int>> adj;
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {5,6};
    adj[5] = {6};
    adj[6] = {4,7};
    adj[7] = {};

    cout<<adj[4].size();

    cout << "Adjacency list is:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " -> { ";
        for (auto &j : adj[i]) {
            cout <<j<<" ";
        }
        cout << "}" << endl;
    }
    stack<int> stk;
    unordered_map<int, bool> visited;

    for(int i=0 ; i<8 ; i++){
        if(!visited[i]){
            dfs1(adj , stk , visited , 0);
        }
    }

    for(int i=0 ; i<8 ; i++){
        for(auto j : adj[i]){
            adj[j].push_back(i);
        }
    }

    cout << "Adjacency list is:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " -> { ";
        for (auto &j : adj[i]) {
            cout <<j<<" ";
        }
        cout << "}" << endl;
    }


    // for(int i=0 ; i<n ; i++){
    //     for()
    // }
}
