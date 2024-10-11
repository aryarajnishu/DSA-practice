#include<iostream>
using namespace std;

int missing(int arr[], int n){
    int a =0;
    for(int j=0 ; j<n ; j++){
        for(int i=0 ; i<n ; i++){
            if(arr[i] == a){
               a++;
            }
        }
    }
    return a;
}

int main(){
    // int arr[10] = {1,2,0,4,6,5,7,3,8,9};
    int arr[1] = {0};
    int ans = missing(arr,1);
    cout<<ans;
}