#include<iostream>
#include<math.h>
using namespace std;
void pairSum(int arr[] , int sum){
    for(int i=0 ; i<10  ; i++){
        for(int j=i+1 ; j<10 ; j++){
            if(arr[i]+arr[j] == sum){
                cout<< arr[i]<<" ";
                cout<< arr[j];
                cout<<endl;
            }
        }
    }
}
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,10};
    pairSum(arr ,10);
}