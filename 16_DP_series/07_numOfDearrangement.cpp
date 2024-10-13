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

int main() {
    int n = 4;
    vector<int> dp(n + 1, -1);
    cout << RcountDerangement(n) << endl;
    cout << McountDerangement(n, dp) << endl;
    return 0;
}
