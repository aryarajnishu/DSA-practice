#include<bits/stdc++.h>
using namespace std;
// inseartion sort    // inseartion sort // inseartion sort // inseartion sort // inseartion sort 
void insertion(vector<int> arr){
    int n = arr.size();
    for(int i=1 ; i<n ; i++){
        int temp = arr[i];
        int j=i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> arr={4,6,8,3,5,2,1,0,7,4,9};
    insertion(arr);
}