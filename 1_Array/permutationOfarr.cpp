#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

void permutations(vector<vector<int> >& res, vector<int> nums, int index) 
{ 
    if (index >= nums.size()) { 
        res.push_back(nums); 
        return; 
    } 
  
    // Permutations made 
    for (int j = index; j < nums.size(); j++) { 
  
        // Swapping 
        swap(nums[index], nums[j]); 
  
        // Calling permutations for 
        // next greater value of l 
        permutations(res, nums, index + 1); 
  
        // Backtracking 
        swap(nums[index], nums[j]); 
    } 
} 
  
// Function to get the permutations 
vector<vector<int> > permute(vector<int>& nums) 
{ 
    // Declaring result variable 
    vector<vector<int> > res; 
    // int x = nums.size() - 1; 
  
    // Calling permutations for the first 
    // time by passing l 
    // as 0 and h = nums.size()-1 
    int index = 0;
    permutations(res, nums, index); 
    return res; 
} 
  
// Driver Code 
int main() 
{ 
    vector<int> nums = { 1, 2, 3 }; 
    vector<vector<int> > res = permute(nums); 
  
    // printing result 
    for (auto x : res) { 
        for (auto y : x) { 
            cout << y << " "; 
        } 
        cout << endl; 
    } 
  
    return 0; 
}