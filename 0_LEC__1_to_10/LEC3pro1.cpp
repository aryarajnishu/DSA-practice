#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n :- "<< endl;
    cin >> n;
    int i=1;
    int sum = 0;
    while(i<=n){
        sum = sum + i;
        i++;
    }
    cout<< "sum is :- "<< sum<<endl;
}