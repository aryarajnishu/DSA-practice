#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
       int *arr;
       int size;
       int top;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        if(size-top>=1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"stack is full"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<" pop not possible"<<endl;
        }
    }
    int peek(){
        if(top>=0 && top<=size){
            return arr[top];
        }
    }
    
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st(5);

    st.push(22);
    st.push(45);
    st.push(29);
    st.push(98);
    cout<<"top is :- "<<st.peek()<<endl;
    return 0;
}