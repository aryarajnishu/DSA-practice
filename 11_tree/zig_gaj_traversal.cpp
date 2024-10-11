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
    // q.push(NULL);
    int count = 1;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        count++;

        // if(temp == NULL){
        //     // cout<<endl;
        //     if(!q.empty()){
        //         q.push(NULL);
        //     }
        // }
        // else{
            if(count%2 == 0){
               cout<<temp->data<<" ";
               if(temp->right){
               q.push(temp->right);
               }
               if(temp->left){
               q.push(temp->left);
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
        // }
    }
}

int main(){
    node* root = NULL;
    building(root);
    cout<<endl;
    levelOrrderTraversalLikeTree(root);
    return 0;
}
