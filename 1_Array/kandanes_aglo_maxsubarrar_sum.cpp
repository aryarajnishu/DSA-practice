#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {-1,2,-3,2};
    // int x = *max_element(nums.begin() , nums.end());
    // cout<<x<<endl;
    int n = nums.size();
    int currrentsum = 0;
    int max_sum = INT_MIN;
    int sum =0;
    for(int i=0 ; i<n ; i++){
        // sum = sum + nums[i];
        currrentsum += nums[i];
        if(currrentsum<0){
            currrentsum = 0;
        }
        max_sum = max(max_sum , currrentsum);
    }
    cout<<"maximun sum is :- "<<max_sum;
    // cout<<sum<<endl;
}