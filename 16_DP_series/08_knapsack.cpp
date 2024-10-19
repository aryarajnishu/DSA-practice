#include <iostream>
#include <vector>
using namespace std;

int recursion(int w, vector<int> &wt, vector<int> &val, int ind) {
    if (ind == 0) {
        return (wt[0] <= w) ? val[0] : 0;
    }
    
    int inc = 0;
    if (wt[ind] <= w) inc = val[ind] + recursion(w - wt[ind], wt, val, ind - 1);
    
    int exc = recursion(w, wt, val, ind - 1);
    
    return max(inc, exc);
}

int memo(int w, vector<int> &wt, vector<int> &val, int ind, vector<vector<int>> &dp) {
    if (ind == 0) {
        return (wt[0] <= w) ? val[0] : 0;
    }

    if (dp[ind][w] != -1) return dp[ind][w];

    int inc = 0;
    if (wt[ind] <= w) inc = val[ind] + memo(w - wt[ind], wt, val, ind - 1, dp);
    
    int exc = memo(w, wt, val, ind - 1, dp);

    dp[ind][w] = max(inc, exc);

    return dp[ind][w];
}



int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 3;
    int w = 6;

    vector<int> wt = {1, 2, 4};
    vector<int> val = {10, 12, 28};

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    int maxValue = knapsack(w, wt, val, n);
    int maxValue1 = recursion(w, wt, val, n - 1);
    int maxValue2 = memo(w, wt, val, n - 1, dp);

    cout << "Maximum value in the knapsack = " << maxValue << endl;
    cout << "Maximum value in the knapsack = " << maxValue1 << endl;
    cout << "Maximum value in the knapsack = " << maxValue2 << endl;

    return 0;
}
