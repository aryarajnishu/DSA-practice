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
void rightPlace(stack<int> &s , int data){
    if(s.empty() || (!s.empty() && s.top()>data)){
        s.push(data);
        return ;
    }
    int num = s.top();
    s.pop();
    rightPlace(s,data);
    s.push(num);
}
void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();

    sort(s);

    rightPlace(s , num);
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(6);
    s.push(9);
    s.push(1);
    s.push(7);
    print(s);
    sort(s);
    print(s);
}