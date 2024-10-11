#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    cout<<"satck is :-"<<" ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void atButtom(stack<int> &s , int data){
    if(s.empty()){
        s.push(data);
        return ;
    }
    int num = s.top();
    s.pop();
    atButtom(s,data);
    s.push(num);
}

int main(){
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(6);
    print(s);
    atButtom(s,1);
    print(s);
}