#include<bits
using namespace std;

// Function to compute rank based on the given constraints
int computeRank(const vector<int>& Vu_vis, const vector<int>& Vu_neigh, const vector<int>& Vu_unv) {
    return Vu_vis.size() + Vu_neigh.size() + Vu_unv.size(); // Example computation, customize as needed
}

vector<int> GreatestConstraintFirst(const unordered_map<int, vector<int>>& graph) {
    vector<int> orderedVertices;          // Ordered list of vertices
    unordered_map<int, int> parentMap;    // Parent mapping of vertices

    // Find the vertex with the maximum degree
    int maxDegreeVertex = -1;
    int maxDegree = -1;
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        int vertex = it->first;
        const vector<int>& neighbors = it->second;
        if (neighbors.size() > maxDegree) {
            maxDegree = neighbors.size();
            maxDegreeVertex = vertex;
        }
    }

    // Initialize data structures
    unordered_set<int> remainingVertices;
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        remainingVertices.insert(it->first);
    }

    remainingVertices.erase(maxDegreeVertex);
    orderedVertices.push_back(maxDegreeVertex);
    parentMap[maxDegreeVertex] = -1; // The first vertex has no parent

    while (!remainingVertices.empty()) {
        int selectedVertex = -1;
        int maxRank = -1;

        // Iterate over the remaining vertices
        for (int u : remainingVertices) {
            vector<int> Vu_vis, Vu_neigh, Vu_unv;

            // Compute Vu_vis: neighbors already in orderedVertices
            for (int v : graph.at(u)) {
                if (find(orderedVertices.begin(), orderedVertices.end(), v) != orderedVertices.end()) {
                    Vu_vis.push_back(v);
                }
            }

            // Compute Vu_neigh: neighbors in remainingVertices
            for (int v : graph.at(u)) {
                if (remainingVertices.find(v) != remainingVertices.end()) {
                    Vu_neigh.push_back(v);
                }
            }

            // Compute Vu_unv: vertices not in the graph but considered neighbors
            for (int v : remainingVertices) {
                if (graph.at(u).end() == find(graph.at(u).begin(), graph.at(u).end(), v)) {
                    Vu_unv.push_back(v);
                }
            }

            // Compute rank
            int rank = computeRank(Vu_vis, Vu_neigh, Vu_unv);

            // Update the selected vertex if rank is higher
            if (rank > maxRank) {
                maxRank = rank;
                selectedVertex = u;
            }
        }

        // Update structures with the selected vertex
        if (selectedVertex != -1) {
            parentMap[selectedVertex] = orderedVertices.back();
            orderedVertices.push_back(selectedVertex);
            remainingVertices.erase(selectedVertex);
        }
    }

    // Output the ordered vertices and parent mapping
    cout << "Ordered Vertices: ";
    for (int vertex : orderedVertices) {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "Parent Map: ";
    for (auto it = parentMap.begin(); it != parentMap.end(); ++it) {
        cout << "(" << it->first << " -> " << it->second << ") ";
    }
    cout << endl;

    return orderedVertices;
}

int main() {
    // Example graph representation as an adjacency list
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0, 3}},
        {3, {1, 2, 4}},
        {4, {3}}
    };

    // Call the algorithm
    vector<int> result = GreatestConstraintFirst(graph);

    return 0;
}
