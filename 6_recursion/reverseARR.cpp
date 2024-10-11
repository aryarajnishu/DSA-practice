#include<iostream>
using namespace std;

void reverse(int arr[], int i, int j){
    if(i>=j){return;}
    swap(arr[i], arr[j]);
    reverse(arr, i++, j--);
}

int main(){
    int arr[10]= {1,5,2,7,8,3,5,4,10,19};
    // reverse(arr, 0, 9);
    for(int x:arr){
        cout<<x<<" ";
    }
}