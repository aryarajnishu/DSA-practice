#include<iostream>
#include<math.h> 
using namespace std;
//Fibonacci     Fibonacci     Fibonacci     Fibonacci 
int fibonacci(int n){
    int a=0 ;
    int b =1;
    int sum =0;
    for(int i=1 ; i<n ; i++){
        a = b;
        b = sum;
        sum = a+b;
    }
    return sum;
}
int main(){
    int n;
    cout<< "Enter n :-";
    cin>>n;
    int x = fibonacci(n);
    cout<< x;
}