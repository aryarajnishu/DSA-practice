#include<iostream>
#include<math.h>
using namespace std;
void intersection(int arr1[] , int arr2[]){
    for(int i=0 ; i<5 ;  i++){
        for(int j=0 ; j<4 ; j++){
            if(arr1[i] == arr2[j]){
                cout<< arr1[i]<<" ";
            }
        }
    }
}
int main(){
    int arr1[5]={2,9,3,6,7};
    int arr2[4]={4,7,3,9};
    intersection(arr1 ,arr2);
}