#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simple swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Taking last element as pivot
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    
    srand(time(NULL));

    // Test with 5 different sizes
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};

    printf("Size\tTime (seconds)\n");
    printf("-------------------\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n];  // Create array of current size

        // Fill array with random numbers
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000;
        }

        // Measure sorting time
        clock_t start = clock();
        quickSort(arr, 0, n-1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%.4f\n", n, time_taken);
    }

    return 0;
}
