#include<iostream>
#include<math.h>
using namespace std;
//squartropt     squartropt     squartropt     squartropt     squartropt
int squartropt(int n){
    int st=0,end = n-1, mid = st + (end-st)/2;
    while(st<end){
        if((mid*mid)<=n && ((mid+1)*(mid+1))>n){
            return mid;
        }
        if((mid*mid) > n){
            end = mid;
        }
        else{
            st = mid;
        }
        mid = st + (end-st)/2;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter a number :- ";
    cin>>n;
    int x = squartropt(n);
    cout<<x;
}