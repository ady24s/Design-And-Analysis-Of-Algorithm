import java.util.Scanner;

public class kanpscenario {

    public static void main(String[] args) {
        // Using predefined values from the scenario
        int n = 5; // Number of items
        int[] weights = {3, 4, 2, 5, 7}; 
        int[] profits = {7, 10, 4, 9, 13};

        // Knapsack capacity from the scenario
        int capacity = 15;

        int[][] dp = new int[n + 1][capacity + 1]; // Create DP table

        // Fill the DP table
        for (int i = 0; i < n; i++) {
            for (int w = 1; w <= capacity; w++) {
                if (weights[i] <= w) {
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

        int maxProfit = dp[n][capacity];
        int w = capacity;
        System.out.print("\nItems in knapsack = ");
        for (int i = n; i > 0 && maxProfit > 0; i--) {
            if (maxProfit != dp[i - 1][w]) {
                System.out.print("Item " + (i) + " ");  // Output the original item index
                w -= weights[i - 1];
                maxProfit -= profits[i - 1];
            }
        }
        System.out.println();

        // Print the maximum profit
        System.out.println("Maximum Profit: " + dp[n][capacity]);
    }
}
