#include<iostream>
#include<math.h>
using namespace std;
void rotate(int arr[],int s , int e){
    while(s<e){
        swap(arr[s++],arr[e--]);
    }
}
int main(){
    int arr[10] = {2,5,1,7,9,3,4,5,6,10};
    rotate(arr,0,9);
    rotate(arr,0,2);
    rotate(arr,3,9);
    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<"   ";
    }
}