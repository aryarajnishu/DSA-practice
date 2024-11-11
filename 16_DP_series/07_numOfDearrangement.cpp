#include <bits/stdc++.h>
using namespace std;

int RcountDerangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (RcountDerangement(n - 1) + RcountDerangement(n - 2));
}

int McountDerangement(int n, vector<int> &dp) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = (n - 1) * (McountDerangement(n - 1, dp) + McountDerangement(n - 2, dp));
    return dp[n];
}

int TcountDerangement(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int ScountDerangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    int pre2 = 1;
    int pre1 = 0;
    int curr;
    for (int i = 2; i <= n; i++) {
        curr = (i - 1) * (pre1 + pre2);
        pre2 = pre1;
        pre1 = curr;
    }
    return curr;
}

int main() {
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << RcountDerangement(n) << endl;
    cout << McountDerangement(n, dp) << endl;
    cout << TcountDerangement(n) << endl;
    cout << ScountDerangement(n) << endl;
    return 0;
}
