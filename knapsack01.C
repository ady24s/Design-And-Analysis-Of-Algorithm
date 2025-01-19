#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> profits(n);
    vector<int> indices(n);  // Vector to track original indices

    for (int i = 0; i < n; i++) {
        indices[i] = i;  // Initialize indices
        cout << "Enter weight for item " << (i + 1) << ": ";
        cin >> weights[i];

        cout << "Enter profit for item " << (i + 1) << ": ";
        cin >> profits[i];
    }

    int capacity;
    cout << "Enter the total capacity of the knapsack: ";
    cin >> capacity;

    // Sort items based on their weights
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return weights[i] < weights[j];
    });

    // Create sorted weights and profits vectors
    vector<int> sortedWeights(n);
    vector<int> sortedProfits(n);
    for (int i = 0; i < n; i++) {
        sortedWeights[i] = weights[indices[i]];
        sortedProfits[i] = profits[indices[i]];
    }

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (sortedWeights[i - 1] <= w) {
                dp[i][w] = max(sortedProfits[i - 1] + dp[i - 1][w - sortedWeights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Output the matrix
    cout << "\nKnapsack Matrix:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    // Find the items included in the knapsack
    int maxProfit = dp[n][capacity];
    int w = capacity;
    cout << "\nItems in knapsack = ";
    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit != dp[i - 1][w]) {
            cout << (indices[i - 1] + 1) << " ";  // Output the original item index
            w -= sortedWeights[i - 1];
            maxProfit -= sortedProfits[i - 1];
        }
    }
    cout << endl;

    cout << "Maximum Profit: " << dp[n][capacity] << endl;

    return 0;
}
