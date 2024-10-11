#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums , int n){
    if(n==0){
        return nums[0];
    }
    if(n<0){
        return 0;
    }

    int incl = solve(nums , n-2) + nums[n];
    int excl = solve(nums , n-1) + 0;

    return max(incl , excl);
}

int solveMEMO(vector<int> &nums , int n , vector<int> dp){
    if(n==0){
        return nums[0];
    }
    if(n<0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int incl = solveMEMO(nums , n-2 , dp) + nums[n];
    int excl = solveMEMO(nums , n-1 , dp) + 0;
    dp[n] = max(incl , excl);
}

int solveTEBU(vector<int> &nums , int n) {
    if(n == 1) return nums[0];  

    vector<int> dp(n, 0);  
    dp[0] = nums[0];      
    dp[1] = max(nums[0], nums[1]);  

    for(int i = 2; i < n; i++) {
        int inc = dp[i-2] + nums[i];  
        int ex = dp[i-1];            
        dp[i] = max(inc, ex);     
    }

    return dp[n-1]; 
}

int optimize(vector<int> &nums , int n) {
    if(n == 1) return nums[0];    

    int prev = nums[0];      
    int curr = max(nums[0], nums[1]);  
    int ans = curr;

    for(int i = 2; i < n; i++) {
        int inc = prev + nums[i];  
        int ex = curr;             
        ans = max(inc, ex); 
        prev = curr;
        curr = ans;    
    }

    return ans; 
}



int main(){
    vector<int> nums = {3,9,7,2};
    int n = nums.size();
    vector<int> dp(n,-1);
    cout<<"Max sum is :- "<<solve(nums, n-1)<<endl;
    cout<<"Max sum is :- "<<solveMEMO(nums, n-1 , dp)<<endl;
    cout<<"Max sum is :- "<<solveTEBU(nums, n)<<endl;
    cout<<"Max sum is :- "<<optimize(nums, n)<<endl;
}