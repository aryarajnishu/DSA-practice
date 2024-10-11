#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(7);
    cout<<"size is :- "<<s.size()<<" "<<endl;
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    if(s.empty()){
        cout<<"stack is empty "<<endl;
    }
    else{
        cout<<" stack is not empty"<<endl;
    }
    cout<<"size is :- "<<s.size()<<endl;
}