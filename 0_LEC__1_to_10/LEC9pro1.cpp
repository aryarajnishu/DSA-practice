#include<iostream>
#include<math.h>
using namespace std;
//print arr   print arr  print arr  print arr

void printarr(int arr[5]){
    for(int i=0 ; i<5 ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5];
    for(int i=0 ; i<5 ; i++){
        cin>>arr[i];
    }
    printarr(arr);
}