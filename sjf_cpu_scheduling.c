#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int pids[MAX_SIZE], burst_times[MAX_SIZE], waiting_times[MAX_SIZE],
        turnaround_times[MAX_SIZE];
    int n, i, j, temp, total_wt_time, total_ta_time;
    float avg_wt_time, avg_ta_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &burst_times[i]);
        pids[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (burst_times[j] > burst_times[j + 1]) {
                temp = pids[j];
                pids[j] = pids[j + 1];
                pids[j + 1] = temp;

                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;
            }
        }
    }

    turnaround_times[0] = burst_times[0];
    for (i = 1; i < n; i++)
        turnaround_times[i] = turnaround_times[i - 1] + burst_times[i];

    total_ta_time = total_wt_time = 0;
    for (i = 0; i < n; i++) {
        waiting_times[i] = turnaround_times[i] - burst_times[i];
        total_wt_time += waiting_times[i];
        total_ta_time += turnaround_times[i];
    }
    avg_wt_time = (float)total_wt_time / n;
    avg_ta_time = (float)total_ta_time / n;

    printf("\nThe execution order is\n");
    printf("PID\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pids[i], burst_times[i],
               waiting_times[i], turnaround_times[i]);
    }
    printf("\nAverage waiting time = %0.2f\n", avg_wt_time);
    printf("Average turnaround time = %0.2f\n", avg_ta_time);

    return 0;
}