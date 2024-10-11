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
// finding minimum element 
node* min(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp ->left;
    }
    return temp;
}
// finding max of tree;
node* max(node* root){
    node* temp = root;
    while(temp->right != NULL){
        temp = temp ->right;
    }
    return temp;
}
// searching of element
node* searchInBST(node* &root , int data){
    node* temp = root;

    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        if(temp->data > data){
            temp = temp ->left;
        }
        else{
            temp = temp -> right;
        }
    }
}

node* deleteNodeInBST(node* root, int val){
    if(root == NULL){
        return root;
    }
    
    if(root->data == val){
        // for 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // for 1 cinld but left;
        else if(root->left == NULL ){
            node* temp = root;
            delete root;
            return temp;
        }

        // for 1 cinld but right;
        else if(root->right == NULL ){
             node* temp = root;
             delete root;
             return temp;
        }

        // having 2 child
        else{
            int min_num = min(root->left)->data;
            root->data = min_num;
            root->right = deleteNodeInBST(root->right , min_num);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteNodeInBST(root->left , val);
        return root;
    }
    else{
        root->right = deleteNodeInBST(root->right , val);
        return root;
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

    cout<<"Enter number which you want to delete :- ";
    int num;
    cin>>num;

    root = deleteNodeInBST(root , num);
    InOrderTraversal(root);
    return 0;
}
