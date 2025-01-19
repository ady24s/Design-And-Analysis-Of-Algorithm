#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int size, int pass) {
    cout << "Pass " << pass << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform insertion sort on sub-arrays
void insertionSort(int arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to find the median of three elements
int medianOfThree(int arr[], int start, int end) {
    int mid = (start + end) / 2;
    if (arr[start] > arr[mid])
        swap(arr[start], arr[mid]);
    if (arr[start] > arr[end])
        swap(arr[start], arr[end]);
    if (arr[mid] > arr[end])
        swap(arr[mid], arr[end]);
    return arr[mid];
}

// Partition function using the median of three as pivot
int partition(int arr[], int start, int end) {
    int pivot = medianOfThree(arr, start, end);
    int i = start;
    int j = end - 1;

    while (true) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[end - 1]);
    return i;
}

// Quick Sort function
void quickSort(int arr[], int start, int end, int size, int& pass) {
    if (start >= end)
        return;

    // Use insertion sort for small sub-arrays
    if (end - start + 1 <= 10) {
        insertionSort(arr, start, end);
        pass++;
        printArray(arr, size, pass);
        return;
    }

    int p = partition(arr, start, end);
    pass++;
    printArray(arr, size, pass);

    quickSort(arr, start, p - 1, size, pass);
    quickSort(arr, p + 1, end, size, pass);
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pass = 0;

    cout << "Initial array: ";
    printArray(arr, n, pass);

    quickSort(arr, 0, n - 1, n, pass);

    cout << "Sorted array: ";
    printArray(arr, n, pass);

    return 0;
}
