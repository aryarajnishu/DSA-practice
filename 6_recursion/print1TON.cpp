#include<iostream>
using namespace std;
void print(int n){
    if(n==0){
        return;
    }
    print(n-1);
    cout<<"arya "<<"  ";
}
int main(){
    
    print(5);
}