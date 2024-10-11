#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n ;
    cout<<"enter n :-";
    cin>>n;
    int a=0;
    for(int i=0 ; i<30 ; i++){
        if(pow(2,i) == n){
            a=1;
            break;
        }
    }
    if(a==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}