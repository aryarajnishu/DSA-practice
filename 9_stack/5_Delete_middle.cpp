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

void middle(stack<int> &s , int count , int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int n = s.top();
    s.pop();
    middle(s,count+1 , size);
    s.push(n);
}



int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(4);
    s.push(8);
    s.push(10);
    middle( s , 0 , 6);
    print(s);
}