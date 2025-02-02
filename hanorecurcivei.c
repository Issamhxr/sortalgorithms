#include <stdio.h>

void hanoi(int n, char start, char intermediate, char finish) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, finish);
        return;
    }
    hanoi(n - 1, start, finish, intermediate);
    printf("Move disk %d from %c to %c\n", n, start, finish);
    hanoi(n - 1, intermediate, start, finish);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}