#include <stdio.h>
#define MAX_SIZE 50

int main() {
    int ioq[MAX_SIZE];
    int n, ihead, i, diff, seek;
    float avg_seek;

    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &ihead);
    ioq[0] = ihead;
    printf("Enter the I/O request queue: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &ioq[i]);

    ioq[n + 1] = ioq[n];
    printf("\nOrder of requests served\n");
    seek = 0;
    for (i = 0; i <= n; i++) {
        diff = ioq[i + 1] - ioq[i];
        if (diff < 0) diff *= -1;
        seek += diff;
        if (i != n)
            printf("%d --> ", ioq[i]);
        else
            printf("%d\n", ioq[i]);
    }
    avg_seek = (float)seek / n;
    printf("Total seek time = %d\n", seek);
    printf("Average seek time = %0.2f\n", avg_seek);
    return 0;
}