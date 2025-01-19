#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int removeDuplicates(int arr[], int size, int duplicates[]) {
    if (size == 0 || size == 1) return size;

    int temp[size];
    int j = 0, d = 0;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        } else if (d == 0 || duplicates[d-1] != arr[i]) {
            duplicates[d++] = arr[i];
        }
    }
    temp[j++] = arr[size - 1];

    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    return d;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* inputArray = new int[n];
    cout << "Randomly generated elements:\n";
    for (int i = 0; i < n; i++) {
        inputArray[i] = rand() % 100; 
        cout << inputArray[i] << " ";
    }
    cout << endl;

    mergeSort(inputArray, 0, n - 1);

    int* duplicates = new int[n];
    int duplicateCount = removeDuplicates(inputArray, n, duplicates);

    cout << "Duplicate elements:\n";
    printArray(duplicates, duplicateCount);

    n -= duplicateCount;

    cout << "Array after removing duplicates:\n";
    printArray(inputArray, n);

    mergeSort(inputArray, 0, n - 1);
    cout << "Sorted array:\n";
    printArray(inputArray, n);

    delete[] inputArray;
    delete[] duplicates;

    return 0;
}
