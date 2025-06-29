
#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int ioq[MAX_SIZE];
    int n, ihead, i, j, temp, start, seek, diff;
    float avg_seek;

    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &ihead);
    printf("Enter the I/O request queue: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &ioq[i]);
    }
    ioq[0] = 0;
    ioq[n + 1] = ihead;
    n += 2;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (ioq[j] > ioq[j + 1]) {
                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
        }
    }
    printf("The request queue is\n");
    for (i = 0; i < n; i++)
        printf("%d ", ioq[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        if (ioq[i] == ihead) {
            start = i;
            break;
        }
    }
    printf("\nOrder of requests served\n");
    seek = 0;
    for (i = start; i > 0; i--) {
        printf("%d --> ", ioq[i]);
        diff = ioq[i] - ioq[i - 1];
        if (diff < 0) diff *= -1;
        seek += diff;
    }
    printf("0 --> ");
    start++;
    diff = ioq[start];
    seek += diff;
    for (i = start; i < n - 1; i++) {
        printf("%d --> ", ioq[i]);
        diff = ioq[i] - ioq[i + 1];
        if (diff < 0) diff *= -1;
        seek += diff;
    }
    printf("%d\n", ioq[n - 1]);
    avg_seek = (float)seek / (n - 2);
    printf("Total seek time = %d\n", seek);
    printf("Average seek time = %0.2f\n", avg_seek);
    return 0;
}
