import java.util.Scanner;

public class Floyd_Traffic {

    final static int INF = 99999;  // Represent infinity for no path
    static int V;  // Number of cities (vertices)

    // Custom class to represent time in minutes and seconds
    static class Time {
        int minutes;  // Stores the minutes part of travel time
        int seconds;  // Stores the seconds part of travel time

        // Constructor to initialize minutes and seconds
        public Time(int minutes, int seconds) {
            this.minutes = minutes;
            this.seconds = seconds;
        }

        // Converts the time into total seconds (minutes * 60 + seconds)
        public int toSeconds() {
            if (this.minutes == INF) {  // If there is no path, return INF
                return INF;
            }
            return this.minutes * 60 + this.seconds;  // Convert minutes and seconds into total seconds
        }

        // toString method to display time in a readable format, e.g., "[5 min 30 sec]"
        // If the time is infinite (INF), it returns "I" to indicate no direct path
        @Override
        public String toString() {
            if (this.minutes == INF) {  // If there's no path, return "I"
                return "I";
            }
            return "[" + this.minutes + " min " + this.seconds + " sec]";
        }
    }

    // Function to implement the Floyd-Warshall algorithm
    public static void floydWarshall(int[][] graph) {

        // Initialize the distance array with the graph (copying graph[][] into dist[][])
        int[][] dist = new int[V][V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];  // Copy the initial travel times into the distance matrix
            }
        }

        // Apply the Floyd-Warshall algorithm
        // The triple loop checks if an intermediate city (k) offers a shorter path between two cities (i, j)
        for (int k = 0; k < V; k++) {  
            for (int i = 0; i < V; i++) {  
                for (int j = 0; j < V; j++) {  
                    // If there's a valid path through city k that is shorter, update dist[i][j]
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];  // Update the shortest path from city i to j
                    }
                    else{
                         // The condition is not met, so no update is needed.
                        // This ensures that the matrix remains unchanged.
                         dist[i][j] = dist[i][j];  // This line is redundant but explicitly keeps the value unchanged
                    }
                }
            }
        }

        // Print the final matrix with the shortest travel times between all cities
        printOptimizedSolution(dist);
    }

    // Function to print the initial travel time matrix in minutes and seconds format
    public static void printInitialSolution(int[][] dist) {
        System.out.println("Initial Travel Time Matrix:");
        for (int i = 0; i < V; i++) {  // Loop through each row (city i)
            for (int j = 0; j < V; j++) {  // Loop through each column (city j)
                if (dist[i][j] == INF) {
                    System.out.print("I ");  // Print "I" for no direct path
                } else {
                    // Convert total seconds back to minutes and seconds for display
                    int minutes = dist[i][j] / 60;
                    int seconds = dist[i][j] % 60;
                    System.out.print("[" + minutes + " min " + seconds + " sec] ");
                }
            }
            System.out.println();  
        }
    }

    // Function to print the optimized travel time matrix in minutes and seconds format
    public static void printOptimizedSolution(int[][] dist) {
        System.out.println("Optimized Travel Time Matrix:");
        for (int i = 0; i < V; i++) {  // Loop through each row (city i)
            for (int j = 0; j < V; j++) {  // Loop through each column (city j)
                if (dist[i][j] == INF) {
                    System.out.print("I ");  // Print "I" for no direct path
                } else {
                    // Convert total seconds back to minutes and seconds for display
                    int minutes = dist[i][j] / 60;
                    int seconds = dist[i][j] % 60;
                    System.out.print("[" + minutes + " min " + seconds + " sec] ");
                }
            }
            System.out.println(); 
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the number of cities (vertices)
        System.out.print("Enter the number of cities (vertices): ");
        V = sc.nextInt();  // Read the number of cities (vertices) from the user

        // Initialize the distance matrix for the travel times between cities
        Time[][] graph = new Time[V][V];

        System.out.println("Enter travel time between cities in matrix form (min sec) or 'I' for no direct path:");

        // Input the travel time matrix from the user
        for (int i = 0; i < V; i++) {  // Loop through each row (city i)
            for (int j = 0; j < V; j++) {  // Loop through each column (city j)
                String input = sc.next();  // Read either 'I' or the time in minutes
                if (input.equals("I")) {
                    graph[i][j] = new Time(INF, 0);  // If no direct path, set it to infinity (INF)
                } else {
                    int minutes = Integer.parseInt(input);  // Read minutes
                    int seconds = sc.nextInt();  // Read seconds
                    graph[i][j] = new Time(minutes, seconds);  // Store the time in the graph
                }
            }
        }

        // Convert the travel times in Time objects to total seconds for easier calculation
        int[][] z = new int[V][V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                z[i][j] = graph[i][j].toSeconds();  // Convert Time to seconds and store in z[][]
            }
        }

        printInitialSolution(z);

        floydWarshall(z);

        sc.close();  // Close the scanner
    }
}
