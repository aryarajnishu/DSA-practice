#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// void fun(TreeNode* root1, TreeNode* &root2, int x) {
//     if (root1 == NULL || root1->val == x) {
//         return;
//     }
    
//     // Create a new node for root2 with the same value as root1
//     root2 = new TreeNode(root1->val);
    
//     // Recursively copy the structure for left and right subtrees
//     fun(root1->left, root2->left, x);
//     fun(root1->right, root2->right, x);
// }

int fun(TreeNode* root1, TreeNode* &root2, int x) {
        if (root1 == NULL || root1->val == x) {
            return 0;
        }

        root2 = new TreeNode(root1->val);
        
        int left = fun(root1->left, root2->left, x);
        int right = fun(root1->right, root2->right, x);

        return max(left , right) + 1;
    }

void levelOrder(TreeNode* root) {
    if (!root) return; 
    
    vector<vector<int>> ans1;
    queue<TreeNode*> q;
    
    q.push(root);

    while (!q.empty()) {
        vector<int> ans;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);

            
                // Check the left child
                if (temp->left) {
                    q.push(temp->left);
                } 
                if (temp->right) {
                    q.push(temp->right);
                }
            
        }
        ans1.push_back(ans);
    }

    // Output the level order traversal
    cout << "Resulting Complete Binary Tree (Level Order):" << endl;
    for (auto i : ans1) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    // Creating the binary tree as described in the test case
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform level order traversal to convert to a complete binary tree
    levelOrder(root);

    TreeNode* root2 = new TreeNode(root->val);
    cout<<fun(root , root2 , 2)<<endl;

    levelOrder(root2);



    return 0;
}
