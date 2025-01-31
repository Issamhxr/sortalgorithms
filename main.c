#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to get digit at position i
int key(int x, int i) {
    while (i > 0) {
        x = x / 10;
        i--;
    }
    return x % 10;
}

// Sort array by digit position i using counting sort
void sortAux(int arr[], int n, int i) {
    int output[n];
    int count[10] = {0}; // Initialize count array for digits 0-9

    // Store count of each digit
    for (int j = 0; j < n; j++)
        count[key(arr[j], i)]++;

    // Change count[i] to contain actual position of digit
    for (int j = 1; j < 10; j++)
        count[j] += count[j - 1];

    // Build output array
    for (int j = n - 1; j >= 0; j--) {
        output[count[key(arr[j], i)] - 1] = arr[j];
        count[key(arr[j], i)]--;
    }

    // Copy output array to arr[]
    for (int j = 0; j < n; j++)
        arr[j] = output[j];
}

// Radix Sort main function
void radixSort(int arr[], int n, int k) {
    // Do counting sort for every digit
    for (int i = 0; i < k; i++)
        sortAux(arr, n, i);
}

// Function to generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Numbers up to 6 digits
    }
}

int main() {
    srand(time(NULL));

    // Using larger sizes
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    int num_trials = 5;

    printf("Size\tAverage Time (seconds)\n");
    printf("-------------------------\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        double total_time = 0;

        for (int trial = 0; trial < num_trials; trial++) {
            int* arr = (int*)malloc(n * sizeof(int));
            generateRandomArray(arr, n);

            clock_t start = clock();
            radixSort(arr, n, 6); // 6 digits maximum
            clock_t end = clock();

            total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
            free(arr);
        }

        printf("%d\t%.6f\n", sizes[i], total_time / num_trials);
    }

    return 0;
}
