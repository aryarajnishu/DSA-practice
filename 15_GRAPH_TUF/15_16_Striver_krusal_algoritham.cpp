#include<bits/stdc++.h>
using namespace std;

int parentis(vector<int> &parent , int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = parentis(parent , parent[n]);
}

void unionByRank(int u , int v , vector<int> &parent , vector<int> &rank){
    int par_u = parentis(parent , u);
    int par_v = parentis(parent , v);

    if(rank[par_u] > rank[par_v]){
        parent[v] = par_u;
    }
    else if(rank[par_u] < rank[par_v]){
        parent[par_u] = par_v;
    }
    else{
        parent[par_u] = par_v;
        rank[par_v]++;
    }
}

void kruskal(int n  , vector<vector<int>> edges){
    
    vector<int> rank(n+1 , 0);
    vector<int> parent(n+1);
    for(int i=0 ; i<=n ; i++){
        parent[i] = i;
    }
    
    int minWeight = 0;
    vector<pair<int,int>> edge;

    sort(edges.begin() , edges.end());

    for(auto i : edges){
        // auto [wt , u , v] = i;
        int wt = i[0];
        int u = i[1];
        int v = i[2];

        if(parentis(parent , u) != parentis(parent , v)){
            minWeight = minWeight + wt;
            edge.push_back({u , v});
            unionByRank(u ,  v, parent , rank);
        }
    }

    cout << "Edges in the MST:\n";
    for (auto &ed : edge) {
        cout << ed.first << " - " << ed.second << endl;
    }
    cout << "Total weight of the MST: " << minWeight << endl;
}

int main(){
    int n = 7;
    vector<vector<int>> edges = {
        {2, 1, 2},
        {1, 1, 4},
        {4, 1, 5},
        {9, 4, 5},
        {5, 4, 3},
        {3, 2, 4},
        {3, 2, 3},
        {2, 6, 7},
        {8, 3, 6}

    };

    kruskal(n , edges);
    return 0;

}