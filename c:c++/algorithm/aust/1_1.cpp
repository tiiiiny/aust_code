
#include <stdio.h>
#define MAX_SIZE 5
void Perm2(int P[], int numbers[], int m, int n) {
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", P[i]);
        }
        printf("\n");
    } else {
        for (int j = 0; j < n; ++j) {
            if (P[j] == 0) {
                P[j] = numbers[m - 1];
                Perm2(P, numbers, m - 1, n);
                P[j] = 0;
            }
        }
    }
}
int main() {
    int numbers[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        scanf("%d", &numbers[i]);
    }
    int P[MAX_SIZE] = {0};
    Perm2(P, numbers, MAX_SIZE, MAX_SIZE);
    return 0;
}