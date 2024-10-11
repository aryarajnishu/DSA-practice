#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z , vector<int> dp) {
    if (n == 0) return 0;
    if (n < 0) return INT_MIN;  

    if(dp[n] != -1){
        return dp[n];
    }

    int a = solve(n - x, x, y, z , dp) + 1;
    int b = solve(n - y, x, y, z , dp) + 1;
    int c = solve(n - z, x, y, z , dp) + 1;

    dp[n] = max(a, max(b, c)); 
    return dp[n];
}

int tebu(int n, int x, int y, int z , vector<int> dp) {
    vector<int> dp(n+1 , -1);

    dp[0] = 0;

    for(int i=0 ; i<=n ; i++){
        if((i-x) >= 0)   dp[i] = max(dp[i] , dp[i-x] + 1);
        if((i-y) >= 0)   dp[i] = max(dp[i] , dp[i-y] + 1);
        if((i-z) >= 0)   dp[i] = max(dp[i] , dp[i-z] + 1);
    }
    return dp[n];
}

int main() {
    int n = 7;
    int x = 5, y = 2, z = 2;

    vector<int> dp(n+1 , -1);

    int ans = solve(n, x, y, z , dp);
    
    
    if (ans < 0) {
        cout << -1 << endl;  
    } else {
        cout << ans << endl;  
    }

    return 0;
}
