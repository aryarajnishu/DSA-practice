#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter n" <<endl;
    cin >> n;
    int nsp = n-1;
    int nst = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<nsp ; j++){
            cout<<"   ";
        }
        for(int k=0 ; k<nst ; k++){
            cout<<"*  ";
        }
        nst=nst+2;
        nsp--;
        cout<< " "<<endl;
    }
}