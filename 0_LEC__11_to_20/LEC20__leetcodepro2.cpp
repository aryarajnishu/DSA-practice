#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
// mearge sorted arr type 1
int main(){
    int arr1[3] = {1,2,5};
    int arr2[7] = {0,6,0,9,16,0,19};
    int ans[12] ;
    int i=0, j=0, k=0;
    while(i<5 && j <7){
        if(arr1[i]<=arr2[j]){
            ans[k++] = arr1[i++];
        }
        if(arr1[i]>arr2[j]){
            ans[k++] = arr2[j++];
        }
    }
    cout<<i<<endl;
    while(i<5){
        ans[k++] = arr1[i++];
    }
    while(j<7){
        ans[k++] = arr2[j++];
    }
    for(int x=0; x<12 ; x++){
        cout<<ans[x]<<"  ";
    }
}