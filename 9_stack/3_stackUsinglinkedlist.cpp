#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Stack{
    public:
    node* top;
    Stack(){
        top=NULL;
    }
    void push(int data){
        node* temp = new node(data);
        temp-> data = data;
        temp-> next = top;
        top = temp;
    }
    bool isempty(){
        return top==NULL;
    }
    void pop(){
        node* temp;
        temp = top;
        top = top->next;
        free(temp);
    }
    int peek(){
        return top->data;
    }
};
int main(){
    Stack s;
    s.push(11);
    s.push(67);
    s.push(89);
    s.push(209);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
}