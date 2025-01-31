#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Basic Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                change = true;
            }
        }
    }
}

// Optimized Bubble Sort implementation
void bubbleSortOpt(int arr[], int n) {
    int m = n - 1;
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < m; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                change = true;
            }
        }
        m--;
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

// Function to measure execution time
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}


int main() {
     srand(time(NULL));

    // Test sizes
    int sizes[] = {1000, 500, 1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int num_trials = 5;  // Number of trials for each size

    printf("Size\tAvg Time (Basic)\tAvg Time (Optimized)\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        double total_time_basic = 0;
        double total_time_opt = 0;

        for (int trial = 0; trial < num_trials; trial++) {
            // Create two identical arrays for fair comparison
            int* arr1 = (int*)malloc(n * sizeof(int));
            int* arr2 = (int*)malloc(n * sizeof(int));

            generateRandomArray(arr1, n);
            // Copy array for fair comparison
            for (int j = 0; j < n; j++) {
                arr2[j] = arr1[j];
            }

            total_time_basic += measureTime(bubbleSort, arr1, n);
            total_time_opt += measureTime(bubbleSortOpt, arr2, n);

            free(arr1);
            free(arr2);
        }

        double avg_time_basic = total_time_basic / num_trials;
        double avg_time_opt = total_time_opt / num_trials;

        printf("%d\t%.6f\t%.6f\n", n, avg_time_basic, avg_time_opt);
    }

    return 0;
}
