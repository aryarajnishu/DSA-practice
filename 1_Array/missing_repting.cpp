#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    sort(arr.begin() , arr.end());
    vector<int> copy(arr.size() + 1 , 0);
    for(auto i : arr){
        copy[i]++;
    }

    // for(int i: copy){
    //     cout<<i<<" ";
    // }cout<<endl;
     
    int rep,miss;

    for(int i = 1 ; i<copy.size() ; i++){
        if(copy[i] == 0) miss = i;
        if(copy[i] > 1) rep = i;
    }
    return {rep,miss};
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,6,8,9};
    // vector<int> arr = {1, 3, 3};
    vector<int> ans = findTwoElement(arr);

    cout<<"ans is :- "<<ans[0]<<" "<<ans[1];
}