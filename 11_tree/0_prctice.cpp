#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void leftview(TreeNode* root , vector<int> &ans ){
    if(root == NULL ){
        return;
    }
    ans.push_back(root->val);
    if(root->left){
        leftview(root->left , ans);
    }
    else{
        leftview(root->right , ans);
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(10);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);

    vector<int> ans;

    leftview(root , ans);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
