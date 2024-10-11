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

node* reversenode(node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    node* ans = reversenode(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;  
}

void print(node* &head){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<"numbers of element in list is :- "<<count<<endl;
}


int main(){
    node* node1 = new node(10);
    node* head = node1;
    insertAthead(head , 1);
    insertAthead(head , 4);
    insertAthead(head , 8);
    insertAthead(head , 12);
    insertAthead(head , 18);
    insertAthead(head , 89);
    insertAthead(head , 67);
    insertAthead(head , 10);
    insertAthead(head , 15);
    insertAthead(head , 89);
    insertAthead(head , 46);
    insertAthead(head , 36);
    print(head);
    cout<<endl;
    head = reversenode(head);
    print(head);
}
