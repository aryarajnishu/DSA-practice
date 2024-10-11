#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int index, unordered_map<int, bool> &visited,  unordered_map<int, bool> &restack , unordered_map<int, vector<int>> &adj, int parent) {
    
    return false;
}

int main() {
    unordered_map<int, vector<int>> adj;
    adj[1] = {2,5};
    adj[2] = {3,5};
    adj[3] = {4};
    adj[4] = {2};
    adj[5] = {};

    unordered_map<int, bool> visited;
    unordered_map<int , bool> restack;
    for (int i = 1; i <= 5; i++) {
        visited[i] = false;
        restack[i] = false;
    }

    for (int i = 1; i <= 5; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, visited,restack, adj, -1);
            if (ans) {
                cout << "Graph contains cycle" << endl;
                return 0;
            }
        }
    }

    cout << "Graph doesn't contain a cycle" << endl;
    return 0;
}




// unordered_map<int, vector<int>> adj;
//     adj[1] = {2,3,4};
//     adj[2] = {1,4};
//     adj[3] = {1,5};
//     adj[4] = {1,2,5};
//     adj[5] = {3,4};