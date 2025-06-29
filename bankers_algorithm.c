#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int alloc[MAX_SIZE][MAX_SIZE], max[MAX_SIZE][MAX_SIZE],
        need[MAX_SIZE][MAX_SIZE];
    int avail[MAX_SIZE], work[MAX_SIZE], finish[MAX_SIZE],
        safe_sequence[MAX_SIZE];
    int n, m, i, j, k, x, y, flag;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    printf("\nNeed matrix is\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    
    for (i = 0; i < n; i++)
        finish[i] = 0;
    x = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safe_sequence[x++] = i;
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("The safe sequence is ");
    for (i = 0; i < n; i++)
        printf("P%d ", safe_sequence[i]);
    printf("\n");
    return 0;
}