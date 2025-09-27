#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& freq, vector<int>& current, vector<vector<int>>& ans) {
    if (current.size() == nums.size()) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) { 
            freq[i] = 1; 
            current.push_back(nums[i]); 
            backtrack(nums, freq, current, ans); 
            current.pop_back(); // undo the choice
            freq[i] = 0; // mark as unused
        }
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<int> freq(nums.size(), 0); // 0 = unused, 1 = used
        backtrack(nums, freq, current, ans);
        return ans;
    }

int main() {
    vector<int> num = {1,2,3};
    vector<vector<int>> ans = permute(num);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
