#include<bits/stdc++.h>
using namespace std;
int binarysort(vector<int> &arr, int target){
    int n = arr.size();
    int s=0,e=n-1,m;
    while(s<e){
        m = e-(e-s)/2;
        if(arr[m]==target){
            return m;
        }
        else if(arr[m]>target){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    sort(arr.begin() , arr.end());
    int target = 11;
    cout<<binarysort(arr, target);
}
