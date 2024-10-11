#include<iostream>
#include<math.h>
using namespace std;
int occurence1(int arr[],int size,int key){
    int st=0;
    int end=size-1;
    int mid = mid = st + (end-st)/2;
    while(st<=end){
        if(arr[mid] == key){
            if(arr[mid] == arr[mid-1]){
                end--;
            }
            else{
                return mid;
            }
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

 int occurence_last(int arr[],int size,int key){
    int st=0;
    int end=size-1;
    int mid = mid = st + (end-st)/2;
    while(st<=end){
        if(arr[mid] == key){
            if(arr[mid] == arr[mid+1]){
                st++;
            }
            else{
                return mid;
            }
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
    int arr[10]={1,2,3,3,3,3,3,5,6,7};
    int ans = occurence1(arr,10,3);
    cout<<"first accurrence is :- "<<ans;
    cout<<endl;
    int ans2 = occurence_last(arr,10,3);
    cout<<"last accurrence  is :- "<<ans2;
}