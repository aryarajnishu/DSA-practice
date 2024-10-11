#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a sample tree
node* build_tree() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
void leftpart(node* root , vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftpart(root->left , ans);
    }
    else{
        leftpart(root->right , ans);
    }
}

void leaftraversal(node* root , vector<int> &ans){
    if(root == NULL ){
        return;
    }
    
     if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    leaftraversal(root->left , ans);
    leaftraversal(root->right , ans);
}

void rightpart(node* root , vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right){
        leftpart(root->right , ans);
    }
    else{
        leftpart(root->left , ans);
    }
    ans.push_back(root->data);
}

int main() {
    node* root = build_tree();
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    cout<<endl;

    vector<int> ans;
    leftpart(root , ans);
    leaftraversal(root,ans);
    rightpart(root , ans);

    ans.pop_back();
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

