#include <stdio.h>
#include <time.h>

void hanoi(int n, char start, char intermediate, char finish) {
    if (n == 1) {
        return;
    }
    hanoi(n - 1, start, finish, intermediate);
    hanoi(n - 1, intermediate, start, finish);
}

int main() {
    int n;
    clock_t start, end;
    double time_taken;

    printf("n\tTime (seconds)\n");
    for (n = 3; n <= 40; n++) {
        start = clock();
        hanoi(n, 'A', 'B', 'C');
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", n, time_taken);
    }
    return 0;
}
