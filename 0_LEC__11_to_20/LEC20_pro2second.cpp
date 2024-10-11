#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
// mearge sorted arr type 1
int main(){
    int arr1[3] = {1,12,25};
    int arr2[7] = {6,0,9,16,0,19,0};
    for(int i=0 ; i<7 ; i++){
        for(int j=i+1 ; j<7 ; j++){
            if(arr2[i]>arr2[j]){
                swap(arr2[i],arr2[j]);
            }
        }
    }
    for(int i=0 ; i<7 ; i++){
        cout<<arr2[i]<<"  ";
    }
    for(int i=0 ; i<3 ; i++){
        arr2[i] = arr1[i];
    }
    cout<<endl;

    for(int i=0 ; i<7 ; i++){
        cout<<arr2[i]<<"  ";
    }
    cout<<endl;

    for(int i=0 ; i<7 ; i++){
        for(int j=i+1 ; j<7 ; j++){
            if(arr2[i]>arr2[j]){
                swap(arr2[i],arr2[j]);
            }
        }
    }
    for(int i=0 ; i<7 ; i++){
        cout<<arr2[i]<<"  ";
    }
}