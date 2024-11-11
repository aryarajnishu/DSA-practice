#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 4, 5, 6};
    int target = 3;

    int it = lower_bound(v.begin(), v.end(), target) - v.begin();

    cout<<v[it];

    return 0;
}
