#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& path, vector<vector<int>>& allPaths) {
    path.push_back(node);

    if (tree[node].size() == 1 && node != 0) {
        allPaths.push_back(path);
    } else {
        // Recur for all adjacent nodes except the parent
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, node, tree, path, allPaths);
            }
        }
    }

    // Backtrack
    path.pop_back();
}

vector<vector<int>> findRootToLeafPaths(int n, vector<vector<int>>& edges) {
    vector<vector<int>> tree(n);   // Adjacency list representation of the tree
    vector<vector<int>> allPaths;  // Stores all root-to-leaf paths

    // Construct the adjacency list
    for (auto& edge : edges) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    vector<int> path;
    dfs(0, -1, tree, path, allPaths);  // Start DFS from root node (0)

    return allPaths;
}

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {1,3}, {3,4}}; // Example input
    int n = 5;  // Number of nodes

    vector<vector<int>> allPaths = findRootToLeafPaths(n, edges);

    // Print all root-to-leaf paths
    cout << "All root-to-leaf paths:\n";
    for (const auto& path : allPaths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    

    return 0;
}
