#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};
void insertAthead(node* &head , int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAttail(node* &tail,int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}


node* reversenode(node* head){
    node* pre = NULL;
    node* curr = head;
    while(curr != NULL){
        node* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    head = pre;
    return head;
}


// node* reversenode(node* head){
//     node* pre = NULL;
//     node* curr = head;
//     node* forword = NULL;
//     while(curr != NULL){
//         forword = curr->next;
//         curr->next = pre;
//         pre = curr;
//         curr = forword;
//     }
//     head = pre;
//     return head;
// }

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}

int main(){
    node* head = new node(1);
    node* tail = head;
    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,4);
    insertAttail(tail,5);
    insertAttail(tail,6);
    print(head);
    cout<<endl;
    head = reversenode(head);
    print(head);
}

