#include<bits/stdc++.h>
using namespace std;

void BFS(unordered_map<int , vector<int> > map , unordered_map<int , bool> &vis ,int node , vector<int> &ans){
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for(auto i : map[temp]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

void DFS(unordered_map<int , vector<int> > map , unordered_map<int , bool> &vis ,int node , vector<int> &ans){
    vis[node] = true;
    ans.push_back(node);

    for(auto i : map[node]){
        if(!vis[i]){
            DFS(map , vis , i , ans);
        }
    }
}

int main(){
    unordered_map<int , vector<int> > map;
    map[0] = {1,2};
    map[1] = {0,2};
    map[2] = {0,1,3,4};
    map[3] = {2};
    map[4] = {2};

    vector<int> ans;
    unordered_map<int , bool> vis;

    // BFS(map , vis ,0 , ans);


    for(int i=0 ; i<5 ; i++){
        if(!vis[i]){
            DFS(map, vis , i , ans);
        }
    }

    DFS(map , vis , 0 , ans);

    for(auto i : ans){
        cout<<i<<" ";
    }

    cout<<endl;

}