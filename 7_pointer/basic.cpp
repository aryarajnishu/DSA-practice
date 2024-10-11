#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    // int* p = &n;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<n<<endl;
    // *p = *p + 1;
    // cout<<*p<<endl;
    // int *q = p;
    // cout<<p<<" - "<<q<<endl;
    // cout<<*p<<" - "<<*q<<endl;


    //arithametic operation :- 
    int *p = &n;
    cout<<*p<<"  "<<*p++<<endl;
    cout<<p<<endl;
    p = p+1;
    cout<<p<<endl;
    
}