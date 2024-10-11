#include<bits/stdc++.h>
using namespace std;

bool linearsort(vector<int> &arr, int target){
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {4,6,5,8,2,8,9,5,6,7};
    int target = 5;
    bool flag = linearsort(arr , target);
    cout<<"is "<<target<<" present ? "<<flag;
}