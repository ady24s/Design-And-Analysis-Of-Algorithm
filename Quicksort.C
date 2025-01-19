#include <iostream>
using namespace std;

void printArray(int arr[], int size, int pass) {
    cout << "Pass " << pass << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end, int size, int& pass) {
    if (start >= end)
        return;

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
