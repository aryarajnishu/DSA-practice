#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void bellman_ford(vector<vector<int>> &edges, int V, int E, int src) {
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;

    // Relax edges (V-1) times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : ";
        if (dis[i] == INT_MAX) cout << "INF\n";
        else cout << dis[i] << "\n";
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

    bellman_ford(adj , Snode , n , m);

    return 0;
}
