#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item i1, Item i2) {
    double ratio1 = static_cast<double>(i1.value) / i1.weight;
    double ratio2 = static_cast<double>(i2.value) / i2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            double fraction = static_cast<double>(capacity) / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    double result = fractionalKnapsack(capacity, items);

    cout << "Maximum value in knapsack = " << result << endl;

    return 0;
}
