import java.util.Scanner;

class Mergejava {

    static int arr[];

    // Merge function
    static void merge(int l, int mid, int h) {
        int n1 = mid - l + 1;
        int n2 = h - mid;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Mergesort function
    static void mergesort(int l, int h) {
        if (l < h) {
            int mid = (l + h) / 2;
            mergesort(l, mid);
            mergesort(mid + 1, h);
            merge(l, mid, h);
        }
    }

    // Function to print array
    static void printArray() {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Main function
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of elements in the array:");
        int n = scanner.nextInt();

        arr = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Given array is:");
        printArray();

        mergesort(0, arr.length - 1);

        System.out.println("\nSorted array is:");
        printArray();

        scanner.close();
    }
}
