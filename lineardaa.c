#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearchFirstOccurrence(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the target element: ");
    scanf("%d", &target);

    clock_t start_time = clock();
    int index = linearSearchFirstOccurrence(arr, n, target);
    clock_t end_time = clock();

    if (index != -1) {
        printf("Element found at %d index\n", index);
    } else {
        printf("Element not found in the array\n");
    }

    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time for linear search: %.6f seconds\n", time_spent);

    free(arr);

    return 0;
}
