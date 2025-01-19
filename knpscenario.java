import java.util.Scanner;

public class knpscenario {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // int n = 5; // Number of items
        // int[] weights = {3, 4, 2, 5, 7}; // Weights of the items
        // int[] profits = {7, 10, 4, 9, 13}; // Profits of the items
        // int capacity = 15; // Knapsack capacity

        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();  

        int[] weights = new int[n];
        int[] profits = new int[n];

        System.out.println("Enter the weights of the items: ");
        for (int i = 0; i < n; i++) {
            System.out.print("Weight of item " + (i + 1) + ": ");
            weights[i] = scanner.nextInt();  
        }

        System.out.println("Enter the profits of the items: ");
        for (int i = 0; i < n; i++) {
            System.out.print("Profit of item " + (i + 1) + ": ");
            profits[i] = scanner.nextInt();  
        }

        System.out.print("Enter the knapsack capacity: ");
        int capacity = scanner.nextInt(); 

        // Initialize the DP table (n + 1 rows for items, capacity + 1 columns for capacity)
        int[][] dp = new int[n + 1][capacity + 1];

        // Outer loop iterates through all items
        for (int i = 0; i < n; i++) {
            // Inner loop iterates through all capacities from 1 to total capacity
            for (int w = 1; w <= capacity; w++) { // w = current knapsack capacity
                // If the current item's weight is less than or equal to the current capacity
                if (weights[i] <= w) {
                    /*dp[i + 1][w] maximum profit we can achieve using the first i + 1 items 
                    (i.e., the current item and all items before it) and a knapsack capacity of w.
                    dp[i][w - weights[i]]: This is the maximum profit we can achieve with the remaining capacity 
                    (w - weights[i]) after including the current item.*/
                    dp[i + 1][w] = Math.max(profits[i] + dp[i][w - weights[i]], dp[i][w]);
                } else {
                    // If the item's weight is too large to include, just carry forward the previous value
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

        // Find the maximum profit that can be achieved (bottom-right corner of the DP table)
        int maxProfit = dp[n][capacity];
        int w = capacity;  // Initialize the remaining capacity to the total capacity

        //This loop traces back through the DP table to figure out which items were included in the optimal solution 
        //(i.e., which items were put in the knapsack to get the maximum profit).

        System.out.print("\nItems in knapsack = ");
        for (int i = n; i > 0 && maxProfit > 0; i--) { 
            // i = n starting from the last element maxprofit > 0 is when all profit is not included
            if (maxProfit != dp[i - 1][w]) { // Item is included
                System.out.print("Item " + (i) + " ");  
                w -= weights[i - 1];
                maxProfit -= profits[i - 1];
            }
        }
        System.out.println();
        System.out.println("Maximum Profit: " + dp[n][capacity]);
        scanner.close();
    }
}
