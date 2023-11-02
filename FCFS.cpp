#include <stdio.h>

int main() {
    int n, total_wait_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wait_time[n], turnaround_time[n];
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    wait_time[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
        total_wait_time += wait_time[i];
    }
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + wait_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    float avg_wait_time = (float)total_wait_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time = %.2f\n", avg_wait_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);

    return 0;
}

