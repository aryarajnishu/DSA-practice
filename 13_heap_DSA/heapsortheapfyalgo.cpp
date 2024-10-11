#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[] , int n , int i){
    int node = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[node]<arr[left]){
        node = left;
    }
    if(right <= n && arr[node]<arr[right]){
        node = right;
    }
    if(node != i){
        swap(arr[node] , arr[i]);
        heapify(arr , n , node);
    }
}

void heapsort(int arr[] , int n){
    int size = n;

    while(size > 1){
        swap(arr[1] , arr[size]);
        size--;

        heapify(arr  , size , 1);
    }
}

int main(){

    int arr[7] = {-1,7,6,3,2,8,5};
    int n = 6;

    cout<<"befor :- "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i = n/2 ; i>0 ; i--){
        heapify(arr , n , i);
    }

    cout<<"after :- "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    heapsort(arr , n);
    
    cout<<"heapsort  :- "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    
}