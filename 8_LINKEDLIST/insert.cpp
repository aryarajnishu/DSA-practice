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

void insertAttail(node* &tail , int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtpositon( node* &head , node* &tail , int position , int data){
    if(position == 1){
        insertAthead(head,data);
        return;
    }
    node* temp = head;
    int pos = 1;
    while(pos < position-1){
        temp = temp->next;
        pos++;
    }
    if(temp->next == NULL){
        insertAttail(tail,data);
        return;
    }
    node* nodeToinsert = new node(data);
     nodeToinsert->next = temp->next;
    temp-> next  =  nodeToinsert;

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
     node* tail = node1;
    insertAttail(tail , 20);
    insertAttail(tail , 30);
    print(head);
    cout<<endl;
    insertAthead(head , 1);
    insertAthead(head , 4);
    insertAthead(head , 8);
    insertAthead(head , 12);
    print(head);
    cout<<endl;
    insertAtpositon( head ,tail, 8 , 110);
    print(head);

}




















