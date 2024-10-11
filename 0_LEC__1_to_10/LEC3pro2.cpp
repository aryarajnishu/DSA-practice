#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n :- "<< endl;
    cin >> n;
    bool flag = true;
    for(int i=3 ; i<=n ; i++){
        for(int j=2 ; j<i ; j++){
            if(i%j==0){
                flag = false;
            }
        }
        if(flag== false){
            cout << i << " is a not prime number"<<endl;
            }
            else{
            cout << i << " is a prime number"<<endl;
            }
    }
}