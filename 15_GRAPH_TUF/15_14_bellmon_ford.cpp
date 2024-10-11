#include <bits/stdc++.h>
using namespace std;

void bellmon_fort(vector<vector<int>> adj , vector<int> &dis , int x , int edge , int node){
    dis[x] = 0;
    for(int i=0 ; i<node-1 ; i++){
        for(int i=0 ; i<edge ; i++){
            int x = adj[i][0] , y = adj[i][1] , w = adj[i][2];
            if(dis[x] + w < dis[y]){
                dis[y] = dis[x] + w;
            }
        }
    }

    for (int j = 0; j < edge; j++) {
        int x = adj[j][0], y = adj[j][1], w = adj[j][2];
        if (dis[x] != INT_MAX && dis[x] + w < dis[y]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout<<"ans is :- ";
    for(int i=0 ; i<node ; i++){
        cout<<dis[i]<<" ";
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

    vector<vector<int>> adj;
    cout << "Enter the edges (format: u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i][0] = u;
        adj[i][1] = v;
        adj[i][2] = w;

    }

    cout<<"our edge is :-";
    for(int i=0 ; i<m ; i++){
        cout<<adj[i][0]<<" "<<adj[i][1]<<" "<<adj[i][2]<<endl;
    }

    
    vector<int> dis(n , INT_MAX);

    bellmon_fort(adj , dis , Snode , n , m);

    return 0;
}
