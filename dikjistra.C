#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum distance value from the
// set of vertices not yet included in the shortest path tree
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the path from the source to a given vertex
void printPath(const vector<int>& parent, int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << " -> " << char('A' + j);
}

// Function to print the constructed distance array and paths
void printSolution(const vector<int>& dist, const vector<int>& parent, int src, int V)
{
    int totalCost = 0;
    cout << "Vertex\t\tDistance\tPath";
    for (int i = 0; i < V; i++)
    {
        cout << "\n" << char('A' + src) << " -> " << char('A' + i) << "\t\t" << dist[i] << "\t\t" << char('A' + src);
        printPath(parent, i);
        totalCost += dist[i];
    }
    cout << "\nTotal minimum cost from " << char('A' + src) << ": " << totalCost << endl;
}

// Function to print the shortest path from 'A' to a specific vertex, here 'E'
void printShortestPathToE(const vector<int>& dist, const vector<int>& parent, int V)
{
    if (V > 4) // Checking if 'E' exists in the vertex set
    {
        cout << "\nShortest path from A to E: A";
        printPath(parent, 4); // 'E' is the 5th vertex, so index 4
        cout << "\nDistance: " << dist[4] << endl;
    }
    else
    {
        cout << "\nVertex 'E' is not present in the graph." << endl;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(const vector<vector<int>>& graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);  // Output array to hold the shortest distance from src to i
    vector<bool> sptSet(V, false); // sptSet[i] is true if vertex i is included in the shortest path tree
    vector<int> parent(V, -1);     // Array to store the shortest path tree

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V); // Pick the minimum distance vertex from those not processed

        sptSet[u] = true; // Mark the picked vertex as processed

        // Update dist[v] only if it's not in sptSet, there is an edge from u to v, 
        // and total weight of path from src to v through u is smaller than the current value of dist[v]
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, parent, src, V);

    // Print the shortest path from A to E (if V > 4)
    printShortestPathToE(dist, parent, V);
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V)); // Dynamically allocate a 2D vector for the graph

    cout << "Enter the adjacency matrix of the graph (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    char source;
    cout << "Enter the source vertex (A-" << char('A' + V - 1) << "): ";
    cin >> source;
    int src = source - 'A'; // Convert character to integer index

    // Call Dijkstra's algorithm
    dijkstra(graph, src, V);

    return 0;
}
