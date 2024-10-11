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

void insertATtail(node* tail,int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

node* reversenode(node* head){
    node* pre = NULL;
    node* curr = head;
    node* forword = NULL;
    while(curr != NULL){
        forword = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forword;
    }
    head = pre;
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
    node* head = new node(1);
    node* tail = head;
    insertATtail(tail,2);
    insertATtail(tail,3);
    insertATtail(tail,4);
    insertATtail(tail,5);
    insertATtail(tail,6);
    print(head);
    // cout<<endl;
    // head = reversenode(head);
    // print(head);
}

