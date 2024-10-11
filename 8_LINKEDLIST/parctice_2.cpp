#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void insertAttail(node* &tail,int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertathead(node* &head,int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}
void insertAtPosition(node* head ,int data , int position){
    node* temp = new node(data);
    if(position == 1){
        insertathead(head,data);
        return;
    }
    else{
        int count = 1;
        node* curr = head;
        while(count < position-1){
            curr=curr->next;
            count++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void printlist(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1 = new node(1);
    node* tail = node1;
    node* head = node1;
    insertAttail(tail , 2);
    insertAttail(tail , 3);
    insertAttail(tail , 4);
    insertAttail(tail , 5);
    insertAttail(tail , 6);
    insertAttail(tail , 7);
    insertAttail(tail , 8);
    printlist(head);
    insertAtPosition(head,38,4);
    printlist(head);
}