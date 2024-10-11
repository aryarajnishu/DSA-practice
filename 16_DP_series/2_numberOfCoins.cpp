#include<bits/stdc++.h>
using namespace std;

// int recursion(vector<int> &coins, int x) {
//     if (x == 0) {
//         return 0;
//     }
//     if (x < 0) {
//         return INT_MAX;
//     }
    

//     int mini = INT_MAX;
    
//     for (int i = 0; i < coins.size(); i++) {
//         int ans = recursion(coins, x - coins[i]);
//         if (ans != INT_MAX) {
//             mini = min(mini, ans + 1);
//         }
//     }

//     return mini;
// }

int funMEMO(vector<int> &coins, int x, vector<int> &dp) {
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return INT_MAX;
    }
    
    if (dp[x] != -1) {
        return dp[x];
    }

    int mini = INT_MAX;
    
    for (int i = 0; i < coins.size(); i++) {
        int ans = funMEMO(coins, x - coins[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, ans + 1);
        }
    }
    
    dp[x] = mini;
    return mini;
}




int funTEBU(vector<int> &coins, int x) {
    
    vector<int> dp(x+1 , INT_MAX);
    dp[0] = 0;
    for(int i=0 ; i<=x ; i++){
        for(int j=0 ; j<coins.size() ; j++){
            if(i-coins[j] >=0 && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i] , 1+dp[i-coins[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX){
        return -1;
    }
    else{
        return dp[x];
    }
}



int main() {
    vector<int> coins = {1, 2, 3};
    int target = 7;
    vector<int> dp(target + 1, -1);  
    // int result = recursion(coins, target);
    // int result = funMEMO(coins, target, dp);
    int result = funTEBU(coins, target);


    if (result == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << result << endl;
    }
}
