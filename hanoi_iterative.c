#include <stdio.h>
#include <math.h>

void hanoi_iterative(int n, char A, char B, char C) {
    int moves = pow(2, n) - 1;
    for (int i = 1; i <= moves; i++) {
        printf("Move disk %d\n", (i & i - 1) % 3 + 1);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi_iterative(n, 'A', 'B', 'C');
    return 0;
}
