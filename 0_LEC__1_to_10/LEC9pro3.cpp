#include<iostream>
#include<math.h>
using namespace std;
//reverse arr   reverse arr   reverse arr   

void reversearr(int arr[]){
   int i=0, j=9;
   while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++,j--;
   }
}
void printarr(int arr[]){
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10] = {2,7,3,8,9,3,10,2,5,28};
    reversearr(arr);
    printarr(arr);
}