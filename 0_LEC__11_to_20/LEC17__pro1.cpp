#include<iostream>
#include<math.h>
using namespace std;
void print_arr(int arr[], int size){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
}
void bubble_sort(int arr[] , int size){
    for(int i=0 ; i<size-1 ; i++){
        bool flag = false;
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            return ;
        }
    }
}
int main(){
    int arr[10]= {2,7,4,9,1,5,3,10,8,6};
    bubble_sort(arr,10);
    print_arr(arr,10);
}