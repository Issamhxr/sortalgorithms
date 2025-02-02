#include <stdio.h>

long long fibo_rec(int n) {
    if (n <= 1) return n;
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

long long fibo_iter(int n) {
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

#include <stdio.h>
#include <time.h>

int main() {
    int n_values[] = {5, 10, 15, 20, 25, 35, 45, 60, 100};
    int size = sizeof(n_values) / sizeof(n_values[0]);

    printf("n\tFibo_Rec (s)\tFibo_Iter (s)\n");

    for (int i = 0; i < size; i++) {
        int n = n_values[i];
        clock_t start, end;
        double time_taken;

        start = clock();
        fibo_rec(n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%lf\t", n, time_taken);

        start = clock();
        fibo_iter(n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%lf\n", time_taken);
    }
    return 0;
}
