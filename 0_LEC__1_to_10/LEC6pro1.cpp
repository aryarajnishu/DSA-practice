#include<iostream>
using namespace std;
// binari to decimal
int main(){
    int n ,y ;
    int x=1;
    int a=0;
    cout<< "Enter n :- ";
    cin>> n;
    while(n >0){
        a = a+((n%2)*x);
        x = x*10;
        n = n/2;
    }
    cout<<a;
}