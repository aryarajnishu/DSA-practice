#include<iostream>
#include<math.h>
using namespace std;   
void selection_sort(int arr[] , int size){
    for(int i=0 ; i<size-1 ; i++){
        int min_index = i;
        for(int j=i+1 ; j<size ; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i] , arr[min_index]);
    }
}
int main(){
    int arr[10]= {2,7,4,9,1,5,3,10,8,6};
    selection_sort(arr,10);
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
}