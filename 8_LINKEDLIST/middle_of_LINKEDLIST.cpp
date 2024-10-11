#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int data){
        this-> val = data;
        this-> next = NULL;
    }
    ~ListNode(){
        int value = this->val;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void insertAttail(ListNode* &tail , int data){
    ListNode* temp = new ListNode(data);
    tail->next = temp;
    tail = temp;
}

void print(ListNode* &head){
    ListNode* temp = head;
    cout<<"List is :-";
    while(temp != NULL){
        cout<<temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insert(ListNode* &head,ListNode* &head2,int a,int b){
    ListNode* temp = head;
    ListNode* temp1 = new ListNode(-1);
    ListNode* temp2 = new ListNode(-1);
    int x = 1;
    while(temp != NULL){
        if(x==(a-1)){
            temp1 = temp;
        }
        if(x==(b+1)){
            temp2 = temp;
        }
        temp = temp->next;
        x++;
    }
    cout<<temp1->val <<" "<<temp2->val<<" "<<endl;
    ListNode* nishu = head2;
    temp1->next = head2;
    while(nishu->next != NULL){
        nishu = nishu->next;
    }
    nishu->next = temp2;
    print(head);
}

int main(){
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(0);
    ListNode* tail2 = node2;
    ListNode* head2 = node2;
    ListNode* tail = node1;
    ListNode* head = node1;
    insertAttail(tail , 1);
    insertAttail(tail , 2);
    insertAttail(tail , 3);
    insertAttail(tail , 4);
    insertAttail(tail , 5);
    insertAttail(tail , 6);

    insertAttail(tail2 , 1);
    insertAttail(tail2 , 9);
    insertAttail(tail2 , 2);
    insertAttail(tail2 , 3);
    print(head);
    print(head2);
    insert(head,head2,2,5);
}
