#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int burst_times[MAX_SIZE], rem_burst_times[MAX_SIZE],
        waiting_times[MAX_SIZE], turnaround_times[MAX_SIZE];
    int n, i, j, t_slice, done, curr_time, total_wt_time,
        total_ta_time;
    float avg_wt_time, avg_ta_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &burst_times[i]);
        rem_burst_times[i] = burst_times[i];
    }
    printf("\nEnter time slice: ");
    scanf("%d", &t_slice);

    done = 0;
    curr_time = 0;
    while (!done) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem_burst_times[i] > 0) {
                done = 0;
                if (rem_burst_times[i] > t_slice) {
                    curr_time += t_slice;
                    rem_burst_times[i] -= t_slice;
                } else {
                    curr_time += rem_burst_times[i];
                    waiting_times[i] = curr_time - burst_times[i];
                    rem_burst_times[i] = 0;
                }
            }
        }
    }

    total_ta_time = total_wt_time = 0;
    for (i = 0; i < n; i++) {
        turnaround_times[i] = burst_times[i] + waiting_times[i];
        total_wt_time += waiting_times[i];
        total_ta_time += turnaround_times[i];
    }
    avg_wt_time = (float)total_wt_time / n;
    avg_ta_time = (float)total_ta_time / n;

    printf("PID\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_times[i], waiting_times[i],
               turnaround_times[i]);
    }
    printf("\nAverage waiting time = %0.2f\n", avg_wt_time);
    printf("Average turnaround time = %0.2f\n", avg_ta_time);

    return 0;
}