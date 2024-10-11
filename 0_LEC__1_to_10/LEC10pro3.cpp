#include<iostream>
#include<math.h>
using namespace std;
int duplicate(int arr[]){
    for(int i=0 ; i<10 ; i++){
        for(int j=i+1 ; j<10 ; j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return 0;
}

int main(){
    int arr[10] = {1,4,7,2,3,9,6,5,8,9};
    int ans = duplicate(arr);
    cout<<"duplicate number is :- "<<ans;
}