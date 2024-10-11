#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter n" <<endl;
    cin >> n;
    for(int x=0 ; x<n ; x++){
        for(int i=0 ; i<n-x ; i++){
            cout<<i+1<<"  ";
        }
        for(int k=0 ; k<2*x ; k++){
            cout<<"*  ";
        }
        for(int j=0 ; j<n-x ; j++){
            cout<<n-x-j<<"  ";
        }
        cout<<"   "<<endl;
    }
}