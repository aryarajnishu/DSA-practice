#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &coins, int x) {
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int ans = recursion(coins, x - coins[i]);
        if (ans != -1) {
            mini = min(mini, ans + 1);
        }
    }
    return mini == INT_MAX ? -1 : mini;
}



int main() {
    vector<int> coins = {1, 2, 3};
    int target = 7;
    int result = recursion(coins, target);

    if (result == -1) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}
