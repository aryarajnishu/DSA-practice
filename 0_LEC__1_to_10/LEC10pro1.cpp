#include<iostream>
#include<math.h>
using namespace std;
//  uniquenumber   uniquenumber   uniquenumber   uniquenumber  
int unique_number(int arr[]){
    for(int i=0 ; i<11 ; i++){
        for(int j=i+1 ; j<11 ; j++){
            if(arr[i] == arr[j] && arr[i]!=0 && arr[j]!=0){
                arr[i] =0;
                arr[j] =0;
            }
        }
    }
    for(int i=0 ; i<10 ; i++){
        if(arr[i] > 0){
            return arr[i];
        }
    }
} 
int main(){
    int arr[11] = {7,6,9,3,10,2,2,6,3,7,9};
    int ans = unique_number(arr);
    cout<<"unique number is :- " <<ans;
}