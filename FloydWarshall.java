import java.util.Scanner;

public class FloydWarshall {

    // Define infinity as a large value for no direct paths
    final static int INF = 99999;

    // Function to implement Floyd-Warshall algorithm
    public static void floydWarshall(int[][] dist, int V) {
        // Display the initial distance matrix
        System.out.println("Initial Distance Matrix:");
        printMatrix(dist, V);

        // Applying the Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // Update dist[i][j] to the minimum distance through vertex k
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Display the final distance matrix
        System.out.println("Final Distance Matrix after Floyd-Warshall:");
        printMatrix(dist, V);
    }

    // Function to print the distance matrix
    public static void printMatrix(int[][] dist, int V) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    System.out.print("I  ");
                else
                    System.out.print(dist[i][j] + "  ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the number of vertices
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();

        // Initialize the distance matrix
        int[][] dist = new int[V][V];

        // Input the distance matrix
        System.out.println("Enter the distance matrix (use I for no path):");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                String input = sc.next();
                if (input.equals("I")) {
                    dist[i][j] = INF;  // Use INF for no path
                } else {
                    dist[i][j] = Integer.parseInt(input);  // Parse numeric input
                }
            }
        }

        // Call the Floyd-Warshall algorithm
        floydWarshall(dist, V);

        sc.close();
    }
}
