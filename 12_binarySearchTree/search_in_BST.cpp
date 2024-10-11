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

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertInToBST(root , data);
        cin>>data;
    }
}

// bool searchInBST(node* &root , int data){
//     if(root == NULL){
//         return false;
//     }
//     if(root->data == data){
//         return true;
//     }
//     if(data > root->data){
//         searchInBST(root->right , data);
//     }
//     else{
//         searchInBST(root->left , data);
//     }
// }

bool searchInBST(node* &root , int data){
    node* temp = root;

    while(temp != NULL){
        if(temp->data == data){
            return true;
        }
        if(temp->data > data){
            temp = temp ->left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}

int main(){

    // 21 10 30 7 13 25 35 -1

    node* root = NULL;
    cout<<"Enter data fot create BST:- "<<endl;
    takeinput(root);

    cout<<"Enter data which you want to search :- ";
    int data;
    cin>>data;
    cout<<"given number is present ? "<<searchInBST(root,data)<<endl;

    return 0;
}
