import matplotlib.pyplot as plt
import numpy as np

# Data for memory usage
x = np.arange(1, 11)  # Number of items
# Simulated memory usage (arbitrary units) for different algorithms
martello_toth_memory = np.array([1, 2, 4, 8, 16, 32, 64, 128, 256, 512])  # Exponential growth
first_fit_decreasing_memory = np.array([1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5])  # Sub-linear growth
best_fit_memory = np.array([1, 1.2, 1.6, 2, 2.4, 3, 3.5, 4, 4.5, 5])  # Slightly more efficient than FFD

# Create the plot
plt.figure(figsize=(8, 6))

# Plot memory usage for Martello and Toth vs. First Fit Decreasing vs. Best Fit
plt.plot(x, martello_toth_memory, label='Martello and Toth (Branch and Bound)', color='red', linestyle='--', marker='o')
plt.plot(x, first_fit_decreasing_memory, label='First Fit Decreasing (FFD)', color='blue', linestyle='-', marker='s')
plt.plot(x, best_fit_memory, label='Best Fit', color='green', linestyle='-', marker='d')

# Add labels and title
plt.title('Memory Usage Comparison of Bin Packing Algorithms', fontsize=14)
plt.xlabel('Number of Items (n)', fontsize=12)
plt.ylabel('Memory Usage (arbitrary units)', fontsize=12)
plt.legend()

# Show grid and the plot
plt.grid(True)
plt.tight_layout()

# Display the plot
plt.show()
