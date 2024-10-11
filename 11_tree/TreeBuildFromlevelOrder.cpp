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

void building(node* &root){
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

int main(){
    node* root = NULL;
    building(root);
    levelOrrderTraversal(root);
    return 0;
}
