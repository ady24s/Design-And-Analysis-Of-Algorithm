#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearchFirstOccurrence(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; 
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        if (mid == 0 || arr[mid - 1] != target) {
            return mid;
        } else {
            return binarySearchFirstOccurrence(arr, left, mid - 1, target);
        }
    } else if (arr[mid] > target) {
        return binarySearchFirstOccurrence(arr, left, mid - 1, target);
    } else {
        return binarySearchFirstOccurrence(arr, mid + 1, right, target);
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the target element: ");
    scanf("%d", &target);

    clock_t start_time = clock();
    int result = binarySearchFirstOccurrence(arr, 0, n - 1, target);
    clock_t end_time = clock();

    if (result != -1) {
        printf("Element found at %d index\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time for binary search: %.6f seconds\n", time_spent);

    free(arr);

    return 0;
}
