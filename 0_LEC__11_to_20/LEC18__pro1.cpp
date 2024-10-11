#include<iostream>
#include<math.h>
using namespace std;
void print_arr(int arr[], int size){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
}
void insertion_sort(int arr[] , int size){
    for(int i=1 ; i<size ; i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j] , arr[j-1]);
            j--;
        }
    }
}
int main(){
    int arr[10]= {2,7,4,9,1,5,3,10,8,6};
    insertion_sort(arr,10);
    print_arr(arr,10);
}
