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

void reverse(node* &head , node* &curr , node* &pre){
    if(curr==NULL){
        head = pre;
        return;
    }
    node* forward = curr->next;
    reverse(head , forward , curr);
    curr->next = pre;
}

node* reversenode(node* head){
    node* pre = NULL;
    node* curr = head;
    reverse(head , curr , pre);
    return head;
}


void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    insertAthead(head , 1);
    insertAthead(head , 4);
    insertAthead(head , 8);
    insertAthead(head , 12);
    print(head);
    cout<<endl;
    head = reversenode(head);
    print(head);
}
