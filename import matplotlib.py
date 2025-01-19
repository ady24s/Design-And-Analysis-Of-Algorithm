import matplotlib.pyplot as plt
import numpy as np

# Data for the time complexity graph
x = np.arange(1, 11)  # Number of items
worst_case = 2 ** x  # Exponential time complexity for worst-case
average_case = np.clip(x ** 2, None, 2 ** x)  # Approximation of average case
best_case = x  # Linear time complexity for best-case

# Create the plot
plt.figure(figsize=(8, 6))

# Plot worst-case, average-case, and best-case complexities
plt.plot(x, worst_case, label='Worst Case: O(2^n)', color='red', linestyle='--', marker='o')
plt.plot(x, average_case, label='Average Case: Between O(n^2) and O(2^n)', color='blue', linestyle='-', marker='s')
plt.plot(x, best_case, label='Best Case: O(n)', color='green', linestyle='-', marker='d')

# Add labels and title
plt.title('Time Complexity of Martello and Toth Algorithm', fontsize=14)
plt.xlabel('Number of Items (n)', fontsize=12)
plt.ylabel('Time Complexity', fontsize=12)
plt.yscale('log')  # Log scale for better visualization
plt.legend()

# Show grid and the plot
plt.grid(True)
plt.tight_layout()

# Show the plot
plt.show()
