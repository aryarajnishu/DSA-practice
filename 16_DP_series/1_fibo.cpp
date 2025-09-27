#include <bits/stdc++.h>
using namespace std;  

int fun1(int n ){
    if(n <= 1) return 1;
    return fun1(n-1) + fun1(n-2);
}

int fun2(int n , vector<int> dp){
    if(n <= 1) return 1;
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fun2(n-1, dp) + fun2(n-2, dp);;
}

int fun3(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fun4(int n){
    if(n <= 1) return 1;
    int prev2 = 1, prev1 = 1, curr;
    for(int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){
    int n = 5;
    vector<int> dp(n+1 , -1);
    cout<<fun1(n);
    cout<<fun2(n , dp);
    return 0;   
}