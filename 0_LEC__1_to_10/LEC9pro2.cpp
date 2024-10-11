#include<iostream>
// #include<math.h>
using namespace std;

int maximum(int arr[] ,int size){
    int maxi = arr[0];
    for(int i=1 ; i<size ; i++){
        maxi = max(maxi , arr[i]);
        // if(arr[i] > max){
        //     max = arr[i];
        // }
    }
    return maxi;
}

int minimum(int arr[] ,int size){
    int mini = arr[0];
    for(int i=1 ; i<size ; i++){
        mini = min(mini , arr[i]);
        // if(arr[i] < min){
        //     min = arr[i];
        // }
    }
    return mini;
}
int main(){
    int arr[10] ={4,7,3,6,9,10,15,23,45,35};
    int max = maximum(arr,10);
    int min = minimum(arr,10);
    cout<< max <<endl;
    cout<< min <<endl;
}