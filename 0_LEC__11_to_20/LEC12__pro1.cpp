#include<iostream>
#include<math.h>
using namespace std;  
//binary  search   binary  search    binary  search
int binary_search(int arr[],int key,int size){
    int st=0;
    int end=size-1;
    int mid = mid = st + (end-st)/2;
    while(st<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }
        else{
            st = mid-1;
        }
        mid = st + (end-st)/2;
    }
    return -1;
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 8;
    int x = binary_search(arr,8,10);
    cout<<"index  of key is :- "<<x;
}