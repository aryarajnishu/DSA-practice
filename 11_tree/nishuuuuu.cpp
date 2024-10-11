#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this-> data = data;
        this-> left = NULL;
        this-> right = NULL;
    }
};

//buinding of tree useing level order tree

void* building(node* &root){
    queue<node*> q;
    cout<<"Enter data for root :- "<<endl;
    int data;
    cin>> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter left node for "<< temp->data<<" " ;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp ->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<< temp->data<<" ";
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp -> right= new node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelOrrderTraversalLikeTree(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
        }
           if(temp->right){
            q.push(temp->right);
           }
        }
    }
}


void solve(node* root , vector<vector<int>> &nums , vector<int> ans){
        
    if (root == NULL) {
        return;
    }
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        nums.push_back(ans);
    } 
    else {
        solve(root->left, nums, ans);
        solve(root->right, nums, ans);
    }
    ans.pop_back();
    }


int main(){
    node* root = NULL;
    building(root);
    levelOrrderTraversalLikeTree(root);
    vector<vector<int>>  nums;
    vector<int> ans;
    solve(root , nums , ans);

    for(int i=0 ; i<nums.size() ; i++){
        for(int j=0 ; j<nums[i].size() ; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
