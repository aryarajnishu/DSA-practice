#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(34);
    q.push(51);
    q.push(98);
    q.push(25);
    cout<<"size is :- "<<q.size()<<endl;
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" "<<endl;
    cout<<"size is :- "<<q.size()<<endl;
}