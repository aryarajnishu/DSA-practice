#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
   int arr[10] ={3,0,1,0,2,0,0,3,2,0};
   for(int i=0 ; i<10-1; i++){
    for(int j=0 ;j<8 ; j++){
        if(arr[j]==0 && arr[j+1]!= 0){
            swap(arr[j] , arr[j+1]);
        }
    }
   }
   for(int i=0 ; i<10 ; i++){
    cout<<arr[i]<<"  ";
   }
}