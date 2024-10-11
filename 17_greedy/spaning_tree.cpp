#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge {
    int source, destination, weight;
};

class Graph {
public:
    int vertices, edges;
    vector<Edge> edgeList;

    Graph(int v, int e) : vertices(v), edges(e) {}

    void addEdge(int src, int dest, int weight) {
        edgeList.push_back({src, dest, weight});
    }

    vector<Edge> kruskalMST();
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

vector<Edge> Graph::kruskalMST() {
    vector<Edge> result;

    sort(edgeList.begin(), edgeList.end(), compareEdges);

    int parent[vertices];
    fill(parent, parent + vertices, -1);

    for (const Edge& edge : edgeList) {
        int x = findParent(parent, edge.source);
        int y = findParent(parent, edge.destination);

        if (x != y) {
            result.push_back(edge);
            unionSets(parent, x, y);
        }
    }

    return result;
}

int main() {
    // Example input
    int vertices = 4;
    int edges = 5;

    Graph graph(vertices, edges);

    // Example edge input
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    vector<Edge> result = graph.kruskalMST();

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : result) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << "\n";
    }

    return 0;
}
