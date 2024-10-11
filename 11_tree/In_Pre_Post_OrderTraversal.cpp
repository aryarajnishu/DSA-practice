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

node* buildtree(node* root){
    cout<<"Enter data :- ";
    int data;
    cin>> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting left of "<<data<<" ";
    root->left = buildtree(root->left);

    cout<<"Enter data for inserting right of "<<data<< " ";
    root->right = buildtree(root->right);
    return root;

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

void InOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    // if(root->left == NULL && root->right ==NULL){
    //     cout<<root->data;
    // }
    InOrderTraversal(root->right);
}

void PreOrderTraversal(node* root){
    if(root == NULL){
        
        return;
    }
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node* root){
    if(root == NULL){
        
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = NULL;
    root = buildtree(root);
    levelOrrderTraversalLikeTree(root);
    cout<<endl;
    cout<<"InOrder Traversal :- ";
    InOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder Traversal :- ";
    PreOrderTraversal(root);
    cout<<endl;
    cout<<"PostOrder Traversal :- ";
    PostOrderTraversal(root);
    return 0;
}
