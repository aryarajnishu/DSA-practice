#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {-1,-3,9,1,-4,8};
    // int s = 0;
    // for(auto x: nums){
    //     s+=x;
    // }
    // cout<<s<<endl;
    int n = nums.size();
    int cumulative[n+1];
    cumulative[0] = 0;//leftsum;
    for(int i=1 ; i<=n ; i++){
        cumulative[i] = cumulative[i-1] + nums[i-1];
    }
    int max_sum = INT_MIN;
    for(int i=1 ; i<=n ; i++){
        int sum =0;
        for(int j=0 ; j<i ; j++){
            sum = cumulative[i]-cumulative[j];
            max_sum = max(sum , max_sum);
        }
    }
    cout<<"maximum sum is :- "<<max_sum;
}