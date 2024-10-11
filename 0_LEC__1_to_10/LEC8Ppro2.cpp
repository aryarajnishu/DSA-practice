#include<iostream>
#include<math.h>
using namespace std;
// number of notes in a amount

int main(){
    int n;
    cout<<"enter amount :-";
    cin>>n;
    cout<<"number of 100 note :- "<< n/100 <<endl;
    n = n - (n/100)*100;
    cout<<"number of 20 note :- "<< n/20 <<endl;
    n = n - (n/20)*20;
    cout<<"number of 5 note :- "<< n/5 <<endl;
    n = n - (n/5)*5;
    cout<<"number of 1 note :- "<< n/1 <<endl;
    n = n - (n/1)*1;
}