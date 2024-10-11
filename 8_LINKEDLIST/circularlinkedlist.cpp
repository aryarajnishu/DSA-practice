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
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<" memory is free for this data "<<value<<endl;
    }
};

void insertnode(node* tail , int element  ,int data){
    //element must be present in linkedllist;
    if(tail == NULL){
        node*temp =  new  node(data);
        tail = temp;
        temp->next = temp;
    }
    else{
        node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        node* temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }

}

void print(node* tail){
    node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail->next != temp);
    cout<<endl;
}

int main(){
    node* tail = NULL;
    insertnode(tail , 5 ,3);
    print(tail);
    return 0;
}




















