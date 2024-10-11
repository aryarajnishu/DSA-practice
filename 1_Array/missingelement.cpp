#include<iostream>
using namespace std;
int missing(int arr[],int n ){
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i]>arr[j]){
            swap(arr[i], arr[j]);
            }
        }
    }
    if(arr[0] != 0){
        return 0;
    }
    for(int i=0 ; i<n-1 ; i++){
        int j= i+1;
        if(arr[i]+1!=arr[j]){
            int x = (arr[i]+arr[j])/2;
            return x;
        }
    }
    
    return n;
}
int main(){
    int arr[10] = {1,2,0,4,10,5,7,3,8,9};
    // int arr[1] = {1};
    int ans = missing(arr,10);
    cout<<ans;
}