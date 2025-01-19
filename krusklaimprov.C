#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

struct Edge {
    int u, v, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    Subset* subsets = new Subset[V];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    vector<Edge> result; 
    int e = 0; 
    int i = 0; 

    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }
    cout << "Edge \tWeight\n";
    int total_cost = 0;
    for (const auto& edge : result) {
        cout << edge.u << " - " << edge.v << " \t" << edge.weight << endl;
        total_cost += edge.weight;
    }
    cout << "\nMinimum Cost: " << total_cost << endl;

    delete[] subsets;
}

int main() {
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    int maxVertex = -1;

    cout << "Enter each edge with its weight (vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u > maxVertex) maxVertex = edges[i].u;
        if (edges[i].v > maxVertex) maxVertex = edges[i].v;
    }

    int V = maxVertex + 1; 

    kruskalMST(edges, V);

    return 0;
}
