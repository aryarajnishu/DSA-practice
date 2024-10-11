#include<iostream>
#include<math.h>
using namespace std;
void shortZeroOne(int arr[]){
    int i=0, j=9;
    while(i<j){
        while(arr[i]==0 && i<j){
            i++;
        }
        while(arr[j]==1 && i<j){
            j--;
        }
        while(arr[i]==1 && arr[j]==0 && i<j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
void printarr(int arr[]){
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10] = {0,0,0,0,1,1,1,0,1,1};
    shortZeroOne(arr);
    printarr(arr);
}