#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge connecting two vertices with a certain weight
struct Edge {
    int vertex1, vertex2, weight;
};

// Comparator function to sort edges based on their weight
// This is used in Kruskal's algorithm to process the smallest edges first
bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the leader (root) of the set that a vertex belongs to
// This function uses path compression to make future searches faster
int findSet(int vertex, vector<int>& parent) {
    if (vertex != parent[vertex])
        parent[vertex] = findSet(parent[vertex], parent); // Recursively find the root and compress the path
    return parent[vertex];
}

// Function to unite (join) two sets (or groups) into one
// It uses union by rank to keep the tree structure balanced
void unionSets(int set1, int set2, vector<int>& parent, vector<int>& rank) {
    if (rank[set1] < rank[set2]) {
        parent[set1] = set2; // If set1's tree is shorter, attach it under set2
    } else if (rank[set1] > rank[set2]) {
        parent[set2] = set1; // If set2's tree is shorter, attach it under set1
    } else {
        parent[set2] = set1; // If both have the same height, attach one to the other and increase the height
        rank[set1]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalMST(vector<Edge>& edges, int numVertices) {
    // Sort all the edges by their weight (from smallest to largest)
    sort(edges.begin(), edges.end(), compareEdge);

    // Initialize parent and rank vectors for the disjoint set (union-find)
    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);

    // Each vertex is initially its own parent (it is its own set)
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    vector<Edge> mstEdges; // This will store the edges that are part of the MST
    int minCost = 0; // This will keep track of the total cost of the MST

    // Process each edge in the sorted order
    for (auto edge : edges) {
        // Find the root of the sets that the edge's vertices belong to
        int set1 = findSet(edge.vertex1, parent);
        int set2 = findSet(edge.vertex2, parent);

        // If the vertices are in different sets, add the edge to the MST
        if (set1 != set2) {
            mstEdges.push_back(edge); // Add this edge to the MST
            minCost += edge.weight;   // Add the weight of this edge to the total cost
            unionSets(set1, set2, parent, rank); // Unite the two sets
        }
    }

    // Output the edges that are part of the MST and the total minimum cost
    cout << "Edges in the MST:" << endl;
    for (auto edge : mstEdges) {
        cout << "Vertex1: " << edge.vertex1 << " - Vertex2: " << edge.vertex2 << " with Weight: " << edge.weight << endl;
    }
    cout << "Minimum Cost: " << minCost << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);
    // Input details for each edge (vertices it connects and its weight)
    for (int i = 0; i < numEdges; i++) {
        cout << "Enter details for edge " << i + 1 << endl;
        cout << "Vertex1: ";
        cin >> edges[i].vertex1;
        cout << "Vertex2: ";
        cin >> edges[i].vertex2;
        cout << "Weight: ";
        cin >> edges[i].weight;
    }

    // Call Kruskal's algorithm to find and print the MST
    kruskalMST(edges, numVertices);

    return 0;
}
