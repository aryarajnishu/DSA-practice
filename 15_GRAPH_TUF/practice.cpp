#include<bits/stdc++.h>
using namespace std;

int parentis(vector<int> &parent , int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = parentis(parent , parent[n]);
}

void findunion(int u , int v , vector<int> &parent , vector<int> &rank){
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

void kruskal(int n , vector<vector<int>> edges){
    int m = edges.size();
    vector<int> parent(n+1);
    vector<int> rank(n+1 , -1);

    for(int i=1 ; i<=n ; i++){
        parent[i] = i;
    }

    sort(edges.begin() , edges.end());

    vector<pair<int,int>> ans;
    int mst = 0;

    for(int i=0 ; i<m ; i++){
        int w = edges[i][0],u = edges[i][1] , v = edges[i][2];

        if(parentis(parent , u) != parentis(parent , v)){
            ans.push_back({u,v});
            mst += w;
            findunion(u , v , parent , rank);
        }
    }

    cout<<"mst is "<<mst;
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