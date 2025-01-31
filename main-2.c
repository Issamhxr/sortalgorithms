#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            // Swap elements
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

double measureTime(int arr[], int n) {
    clock_t start = clock();
    gnomeSort(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    // Test sizes
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int num_trials = 5;  // Number of trials for each size

    printf("Size\tAverage Time (seconds)\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        double total_time = 0;

        for (int trial = 0; trial < num_trials; trial++) {
            int* arr = (int*)malloc(n * sizeof(int));
            generateRandomArray(arr, n);

            total_time += measureTime(arr, n);

            free(arr);
        }

        double avg_time = total_time / num_trials;
        printf("%d\t%.6f\n", n, avg_time);
    }

    return 0;
}
