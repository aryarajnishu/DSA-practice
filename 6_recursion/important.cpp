#include<bits/stdc++.h>
using namespace std;
void f(int n ){
    if(n>0){
        cout<<n<<" ";
        f(n-1);
        f(n-1);
    }
}
int main(){
    int n=3;
    f(n);
}