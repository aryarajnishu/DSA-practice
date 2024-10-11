#include<bits/stdc++.h>
using namespace std;

void f(int n){
    if(n>0){
        cout<<n<<" ";
        f(n-1);
        cout<<n<<" ";
        f(n-1);
    }
}

int main(){
    f(3);
}