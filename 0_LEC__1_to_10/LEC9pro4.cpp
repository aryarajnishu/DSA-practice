#include<iostream>
#include<math.h>
using namespace std;
//alternatechage    alternatechage   alternatechage
 void alternatechage(int arr[]){
    int i=0, j=1;
    while(i<10 || j<10){
        // int temp = arr[i];
        // arr[i] = arr[j];
        // arr[j] = temp;
        swap(arr[i] , arr[j]);
        i=i+2,j=j+2;
    }
 }

void printarr(int arr[]){
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    alternatechage(arr);
    printarr(arr);
}