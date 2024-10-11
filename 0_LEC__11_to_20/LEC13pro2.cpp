#include<iostream>
#include<math.h>
using namespace std;
int pic_element(int arr[],int size){
    int st=0,end=size-1,mid = st + (end-st)/2;
    while(st<=end){
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid]>arr[mid-1]){
            st = mid+1;
        }
        if(arr[mid]>arr[mid+1]){
            end  = mid-1;
        }
        mid = st + (end-st)/2;
    }
}
int main(){
    int arr[14] = {4,5,6,7,8,7,6,5,4,3,2,1,0,-1};
    int x = pic_element(arr,14);
    cout<<"Pic element of an arr ia at "<<x<<"th position.";
}