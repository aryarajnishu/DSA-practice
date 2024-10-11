#include<iostream>
#include<math.h>
using namespace std;
//pivot    pivot    pivot    pivot    pivot
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
            return arr[mid];
        }
        mid = st + (end-st)/2;
    }
    return -1;
}
int main(){
    int arr[14]={9,10,11,12,13,14,1,2,3,4,5,6,7,8};
    int x = pivot(arr,14);
    cout<<"pivot element is "<<x;
}