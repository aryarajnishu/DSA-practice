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

node* insertInToBST(node* root , int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertInToBST(root->left , data);
    }
    else{
        root->right = insertInToBST(root->right , data);
    }
    return root;
}

// void takeinput(node* root){
//     cout<<"Enter 1st element :- ";
//     int data;
//     cin>>data;
//     int count = 2;
//     while(data != -1){
//         root = insertInToBST(root , data);
//         cout<<"Enter "<<count<< "th element :- ";
//         cin>>data;
//         count++;
//     }
// }

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertInToBST(root , data);
        cin>>data;
    }
}

void levelOrrderTraversalLikeTree(node* root){
    queue<node*>q;
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

    // 21 10 30 7 13 25 35 5 9 12 14 22 27 32 40 -1

    node* root = NULL;
    cout<<"Enter data fot create BST:- "<<endl;
    takeinput(root);

    cout<<"printing the BST:- "<<endl;
    levelOrrderTraversalLikeTree(root);
    cout<<endl;

    cout<<"printing InOrder :- "<<endl;
    InOrderTraversal(root);
    cout<<endl;

    cout<<"printing pre-Order :- "<<endl;
    PreOrderTraversal(root);
    cout<<endl;

    cout<<"printing post-Order :- "<<endl;
    PostOrderTraversal(root);

    return 0;
}
