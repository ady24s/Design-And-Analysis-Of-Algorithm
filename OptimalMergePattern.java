import java.util.PriorityQueue; // it is used as a min-heap to efficiently retrieve the smallest file sizes.
import java.util.Scanner;

public class OptimalMergePattern {

    //Declares a static method named minComputation
    //takes an array of integers (files) representing the sizes of the files to be merged.
    static int minComputation(int[] files) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        //Initializes a new PriorityQueue of integers.

        // Java's PriorityQueue is a min-heap, meaning the smallest element is always at the front.
        for (int file : files) { //Iterates over each file size in the files array.
            pq.add(file);//Adds each file size to the priority queue. This ensures that the smallest files are always accessible first.
        }

        int totalComputations = 0;
        //accumulate the total number of computations (merge costs) required to merge all files.

        // Merge files until one file remains
        while (pq.size() > 1) { //Removes and returns the smallest element from the priority queue.
            int smallest = pq.poll(); //Retrieves and removes the smallest file size.
            int secondSmallest = pq.poll(); //Retrieves and removes the next smallest file size.

             // prints the sizes of the two smallest files being merged at each step of the process.
             System.out.println("Merging files of sizes: " + smallest + " and " + secondSmallest);

             int mergeCost = smallest + secondSmallest; // calculates the cost of merging the two smallest files by summing their sizes.
             totalComputations += mergeCost; //totalComputations accumulates the total cost of merging all the files.
 
             System.out.println("Merge cost: " + mergeCost);
 
             // Add the merged file size back to the queue
             pq.add(mergeCost);
 
             // Display the updated queue after each merge
             System.out.println("Updated Queue: " + pq);
        }

        return totalComputations;
        //totalComputations variable, which holds the total cost of merging all the files, is returned.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user to define the number of files
        System.out.print("Enter the number of files: ");
        int numFiles = scanner.nextInt();

        // Ask the user to input the sizes of the files
        int[] fileSizes = new int[numFiles];
        System.out.println("Enter the sizes of the files:");
        for (int i = 0; i < numFiles; i++) {
            fileSizes[i] = scanner.nextInt();
        }

        //This method is called with the array fileSizes as input.
        // It calculates and returns the total number of computations required to merge all the files.

        int result = minComputation(fileSizes);
        System.out.println("Minimum Computations = " + result);

        scanner.close();
    }
}
