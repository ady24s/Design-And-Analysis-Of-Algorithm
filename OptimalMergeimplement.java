import java.util.PriorityQueue;
import java.util.Scanner;

class File {
    int size;
    double multiplier;

    File(int size, double multiplier) {
        this.size = size;
        this.multiplier = multiplier;
    }
}

public class OptimalMergeimplement{

    // Function to calculate the minimum cost with constraints
    static double minComputation(File[] files) {
        PriorityQueue<File> pq = new PriorityQueue<>((a, b) -> a.size - b.size); // Min-heap based on file size

        // Add files to the priority queue
        for (File file : files) {
            pq.add(file);
        }

        double totalComputations = 0;
        int mergeOperations = 0;

        // Merge files until one file remains or the merge limit is reached
        while (pq.size() > 1 && mergeOperations < 15) {
            File smallest = pq.poll();
            File secondSmallest = pq.poll();

            // Calculate the merged file size and check if it exceeds 500 GB
            int mergedSize = smallest.size + secondSmallest.size;
            if (mergedSize > 500) {
                System.out.println("Merging these files exceeds the size limit of 500 GB. Aborting further merges.");
                break;
            }

            // Calculate the merge cost considering the multipliers
            double mergeCost = (smallest.size * smallest.multiplier) + (secondSmallest.size * secondSmallest.multiplier);
            totalComputations += mergeCost;
            mergeOperations++;

            // Calculate the average multiplier for the merged file
            double newMultiplier = (smallest.multiplier + secondSmallest.multiplier) / 2;

            // Add the merged file back to the queue with the average of the two multipliers
            pq.add(new File(mergedSize, newMultiplier));

            // Print the details of the merge
            System.out.println("Merged files of sizes: " + smallest.size + " and " + secondSmallest.size 
                + " -> New size: " + mergedSize + ", New multiplier: " + newMultiplier);
            System.out.println("Merge cost: " + mergeCost);
        }

        return totalComputations;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // File sizes and multipliers from the problem statement
        File[] files = new File[8];
        files[0] = new File(150, 1.2);
        files[1] = new File(200, 1.5);
        files[2] = new File(80, 1.1);
        files[3] = new File(120, 1.3);
        files[4] = new File(300, 1.4);
        files[5] = new File(50, 1.0);
        files[6] = new File(90, 1.2);
        files[7] = new File(60, 1.3);

        // Calculate and display the minimum computations
        double result = minComputation(files);
        System.out.println("Total Merging Cost = " + result);

        scanner.close();
    }
}
// display files included and costs an