#include<iostream>
#include<math.h>
using namespace std;

void print_arr(int arr[]){
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10]={3,2,3,1,4,2,3,4,4,4};
    for(int i=0 ; i<10 ; i++){
        for(int j=i+1 ; j<10 ; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    print_arr(arr);
}