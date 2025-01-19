#include <iostream>
#include <limits.h> 
using namespace std;

void primMST(int** graph, int V);

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;  
        }
    }

    cout << "Enter each edge with its weight (vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;  
    }

    primMST(graph, V);

    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int** graph, int V) {
    cout << "Edge \tWeight\n";
    int total_cost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        total_cost += graph[i][parent[i]];
    }
    cout << "\nMinimum Cost: " << total_cost << endl;
}

void primMST(int** graph, int V) {
    int* parent = new int[V];  
    int* key = new int[V];     
    bool* mstSet = new bool[V]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}
