#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // Declare a map with key as int, and the corresponding value as another map
    // Inner map has a key as int and value as a vector of ints
    map<int, map<int, vector<int>>> nodes;

    // Inserting elements into the map
    nodes[0][0].push_back(1);
    nodes[0][0].push_back(2);
    nodes[1][-1].push_back(3);
    nodes[1][1].push_back(4);
    nodes[-1][0].push_back(5);

    // Accessing elements of the map
    cout << "Value at key 0, 0: ";
    for (int val : nodes[0][0]) {
        cout << val << " ";
    }
    cout << endl;

    // Iterating over the entire map
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        cout << "Key: " << it->first << endl;
        for (auto inner_it = it->second.begin(); inner_it != it->second.end(); ++inner_it) {
            cout << "\tInner Key: " << inner_it->first << ", Values: ";
            for (int val : inner_it->second) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
