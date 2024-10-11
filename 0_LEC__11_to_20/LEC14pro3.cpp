#include<iostream>
#include<math.h>
using namespace std;
//find__pivot     find__pivot   find__pivot   find__pivot   find__pivot   
int pivot(int arr[] ,int size ){
    int st=0,end = size-1,mid = st + (end-st)/2;
    while(st<=end){
        if(arr[mid] > arr[0]){
            st=mid;
        }
        if(arr[mid]<arr[0]){
            end = mid;
        }
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            return mid;
        }
        mid = st + (end-st)/2;
    }
    return -1;
}
int find_In_shorted_arr(int arr[], int size , int key){
    int st=0,end = size-1,mid = st + (end-st)/2,x = pivot(arr,size );
    while(st<=end){
        if(key>arr[x] && key<arr[size-1]){
            st = x;
            end = size-1;
            if(arr[mid]>key){
                end = mid;
            }
            else{
                st = mid;
            }
            if(arr[mid]== key){
                return 1;
            }
            mid = st + (end-st)/2;
        }
        if(key<arr[x-1] && key>arr[0]){
            end = x-1;
            st = 0;
            if(arr[mid]>key){
                end = mid;
            }
            else{
                st = mid;
            }
            if(arr[mid]== key){
                return 1;
            }
            mid = st + (end-st)/2;
        }
    }
    return 0;
}
int main(){
    int arr[14]={9,10,11,12,13,14,1,2,3,4,5,6,7,8};
    cout<<find_In_shorted_arr(arr,14,19);
}