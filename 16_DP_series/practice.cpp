#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& prices, int k) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));

    for (auto t = 1; t <= k; ++t) {
        int maxDiffNormal = -prices[0];
        int maxDiffShort = prices[0];
        for (auto d = 1; d < n; ++d) {
            // Max of:
            // 1. Not transacting on day d
            // 2. Completing a normal transaction on day d
            // 3. Completing a short sell transaction on day d
            dp[t][d] = max({dp[t][d - 1],
                            prices[d] + maxDiffNormal, // Normal: sell today
                            -prices[d] + maxDiffShort  // Short: buy back today
                           });

            // Update max difference for next day
            maxDiffNormal = max(maxDiffNormal, dp[t - 1][d - 1] - prices[d]);
            maxDiffShort = max(maxDiffShort, dp[t - 1][d - 1] + prices[d]);
        }
    }

    return dp[k][n - 1];
}

int main() {
    vector<int> prices = {12,16,19,19,8,1,19,13,9};
    int k = 3;
    cout << "Max Profit: " << fun(prices, k) << endl;  // Output: 14
    return 0;
}
