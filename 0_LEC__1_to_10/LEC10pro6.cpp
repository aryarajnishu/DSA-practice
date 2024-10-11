#include<iostream>
#include<math.h>
using namespace std;

void pairSum(int arr[] , int sum){
    for(int i=0 ; i<20  ; i++){
        for(int j=i+1 ; j<20 ; j++){
            for(int k=j+1 ; k<20 ; k++){
                if(arr[i]+arr[j]+arr[k] == sum){
                cout<< arr[i]<<" ";
                cout<< arr[j]<<" ";
                cout<< arr[k];
                cout<<endl;
            }
            }
        }
    }
}
int main(){
    int arr[20] = {0,1,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19,20};
    pairSum(arr ,20);
}