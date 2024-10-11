#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4]={23,65,90,34};
    cout<<arr<<endl;
    for(int i=0 ; i<4 ; i++){
        cout<<&arr[i]<<"  ";
    }
    cout<<endl;
    cout<<*arr<<endl;
    
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;
}