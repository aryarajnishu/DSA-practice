#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

bool pairsum(vector<int> &nums,int k){
    sort(nums.begin() , nums.end());
    int n = nums.size();
    int i=0,j=0;
    while(i<j){
        if(nums[i] + nums[j] < k){
            i++;
        }
        else if(nums[i] + nums[j] > k){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> nums = {2,1,4,6,7,12};
    int k = 9;
    cout<<pairsum(nums,k);
}