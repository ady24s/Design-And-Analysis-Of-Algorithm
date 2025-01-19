import java.util.Scanner;

public class knapsackfull {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = scanner.nextInt();

        int[] weights = new int[n];  // Storing profits and weights in arrays
        int[] profits = new int[n];

        for (int i = 0; i < n; i++) {  // Ente weights and profits 
            System.out.print("Enter weight for item " + (i + 1) + ": ");
            weights[i] = scanner.nextInt();

            System.out.print("Enter profit for item " + (i + 1) + ": ");
            profits[i] = scanner.nextInt();
        }

        System.out.print("Enter the total capacity of the knapsack: ");
        int capacity = scanner.nextInt();

        // Sort weights and corresponding profits together
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (weights[j] > weights[j + 1]) {
                    // Swap weights
                    int tempWeight = weights[j];
                    weights[j] = weights[j + 1];
                    weights[j + 1] = tempWeight;

                    // Swap profits 
                    int tempProfit = profits[j];
                    profits[j] = profits[j + 1];
                    profits[j + 1] = tempProfit;
                }
            }
        }

        int[][] dp = new int[n + 1][capacity + 1]; // declares a 2D array dp with dimensions (n + 1) x (capacity + 1).
        // rows = n+1 
        //columns = capacity +1

        // dp[i][w] will store the maximum profit that can be obtained with the first i items and a knapsack capacity of w.
        for (int i = 0; i < n; i++) {  
            for (int w = 1; w <= capacity; w++) {
                if (weights[i] <= w) { 
                    // Check if the weight of the current item (weights[i]) can be included in the knapsack with capacity w
                    dp[i + 1][w] = Math.max(profits[i] + dp[i][w - weights[i]], dp[i][w]); 
                } else {
                    dp[i + 1][w] = dp[i][w];
                }
            }
        }
        
        System.out.println("\nKnapsack Matrix:");
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                System.out.print(dp[i][w] + "\t");
            }
            System.out.println();
        }

        // Find the items included in the knapsack
        int maxProfit = dp[n][capacity];
        int w = capacity;
        System.out.print("\nItems in knapsack = ");
        for (int i = n; i > 0 && maxProfit > 0; i--) {
            if (maxProfit != dp[i - 1][w]) {
                System.out.print(i + " ");  // Output the original item index
                w -= weights[i - 1];
                maxProfit -= profits[i - 1];
            }
        }
        System.out.println();

        System.out.println("Maximum Profit: " + dp[n][capacity]);

        scanner.close();
    }
}
