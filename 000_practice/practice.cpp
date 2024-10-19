#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums , int ind , vector<int> &temp , vector<vector<int>> &ans){
    if(ind >= nums.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[ind]);

    solve(nums , ind+1 , temp , ans);
    temp.pop_back();
    solve(nums , ind+1 , temp , ans);

}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    solve(nums , 0 , temp , ans);

    for(auto i: ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}