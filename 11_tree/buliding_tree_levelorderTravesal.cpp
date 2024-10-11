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

void levelOrrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
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

int main(){
    node* root = NULL;
    root = buildtree(root);
   
    cout<<endl;
    levelOrrderTraversalLikeTree(root);
    return 0;
}
