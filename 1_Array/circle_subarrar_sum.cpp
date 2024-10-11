#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

int kadanes(vector<int> &ans ){
    int n = ans.size();
    int currentSum = 0;
    int max_sum = INT_MIN;
    for(int i=0 ; i<n ; i++){
        currentSum += ans[i];
        if(currentSum <0){
            currentSum = 0;
        }
        max_sum = max(max_sum , currentSum);
    }
    return max_sum;
}

int main(){
    vector<int> nums = {1,-2,3,-2};
    int sum = 0;
    for(int i=0 ; i<nums.size() ; i++){
        sum += nums[i];
        nums[i] = -nums[i];
    }
    int x = sum - (-kadanes(nums));
    cout<<x;
}