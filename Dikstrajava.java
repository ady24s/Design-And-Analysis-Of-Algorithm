import java.util.Scanner;

public class Dikstrajava {
    static final int V = 11;
    static final int INF = Integer.MAX_VALUE;

    // Function to find the vertex with minimum distance value,
    // from the set of vertices not yet included in shortest path tree
    int minDistance(int[] dist, boolean[] sptSet) {
        int min = INF, min_index = -1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        return min_index;
    }

    // Function to print the path from source to a given vertex
    void printPath(int[] parent, int j) {
        if (parent[j] == -1)
            return;

        printPath(parent, parent[j]);
        System.out.print(" -> " + (char) ('A' + j));
    }

    // Function to print the constructed distance array and paths
    void printSolution(int[] dist, int[] parent, int src) {
        int totalCost = 0;
        System.out.println("Vertex\t\tDistance\tPath");
        for (int i = 0; i < V; i++) {
            System.out.print("\n" + (char) ('A' + src) + " -> " + (char) ('A' + i) + "\t\t" + dist[i] + "\t\t\t" + (char) ('A' + src));
            printPath(parent, i);
            totalCost += dist[i];
        }
        System.out.println("\nTotal minimum cost from " + (char) ('A' + src) + ": " + totalCost);
    }

    // Function to print the shortest path from 'A' to 'E'
    void printShortestPathToE(int[] dist, int[] parent) {
        System.out.print("\nShortest path from A to E: A");
        printPath(parent, 4); // 'E' is the 5th vertex, so index 4
        System.out.println("\nDistance: " + dist[4]);
    }

    // Function that implements Dijkstra's single source shortest path
    // algorithm for a graph represented using adjacency matrix representation
    void dikstra(int[][] graph, int src) {
        int[] dist = new int[V];  // The output array. dist[i] will hold the shortest distance from src to i
        boolean[] sptSet = new boolean[V]; // sptSet[i] will be true if vertex i is included in shortest path tree
        int[] parent = new int[V]; // Array to store shortest path tree

        // Initialize all distances as INFINITE and sptSet[] as false
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            sptSet[i] = false;
            parent[i] = -1;
        }

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not yet processed.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < V; v++) {
                // Update dist[v] if it is not in sptSet, there is an edge from u to v,
                // and total weight of path from src to v through u is smaller than current value of dist[v]
                if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        // Print the constructed distance array
        printSolution(dist, parent, src);

        // Print the shortest path from A to E
        printShortestPathToE(dist, parent);
    }

    public static void main(String[] args) {
        Dikstrajava t = new Dikstrajava();
        Scanner scanner = new Scanner(System.in);

        int[][] graph = new int[V][V];

        System.out.println("Enter the adjacency matrix for the graph (11x11 matrix):");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter the source vertex (0 for A, 1 for B, ..., 10 for K):");
        int src = scanner.nextInt();

        // Function call
        t.dikstra(graph, src);

        scanner.close();
    }
}
