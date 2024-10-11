#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
       int *arr;
       int size;
       int front;
       int rear;
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void push(int data){
        if(rear<size){
            rear++;
            arr[rear] = data;
        }
        else{
            cout<<"overflow condition"<<endl;
        }
    }
    void pop(){
        if(rear - front >= 1){
            front++;
        }
        else{
            cout<<"under flow condition "<<endl;
        }
    }
    bool isempty(){
        return rear-front;
    }
    int f(){
        return arr[front];
    }
};

int main(){
    Queue q(5);
    q.push(28);
    q.push(86);
    q.push(98);
    q.push(34);
    cout<<q.f()<<endl;
    q.pop();
    cout<<q.f()<<endl;
}