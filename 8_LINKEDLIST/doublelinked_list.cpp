#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* pre;
    node* next;
    node(int data){
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

void inrertAthead(node* &head , int data){
    node* temp = new node(data);
    head->pre = temp;
    temp->next = head;
    head = temp;
}

void insertAttail(node* tail , int data){
    node* temp = new node(data);
    tail->next = temp;
    temp->pre = tail;
    tail = temp;
}

void insertAtpositon( node* &head , node* &tail , int position , int data){
    if(position == 1){
        inrertAthead(head,data);
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
    temp->next->pre = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->pre = temp;

}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlenght(node* head){
    node* temp = head;
    int lenght = 0;
    while(temp != NULL){
        lenght++;
        temp = temp->next;
    }
    return lenght;
}

int main(){
    cout<<"i am learning doublylinkedlist "<<endl;
    node* node1 = new node(40);
    node* head = node1;
    node* tail = node1;
    print(head);
    inrertAthead(head , 30);
    inrertAthead(head , 20);
    inrertAthead(head , 10);
    print(head);
    insertAttail(tail , 50);
    print(head);
    insertAtpositon(head , tail , 2 , 100);
    print(head);
    cout<<"zise of linked list :- "<<getlenght(head);
}