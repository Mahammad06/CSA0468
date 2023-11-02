#include <stdio.h>

int main() {
    int num_processes, quantum, total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &num_processes);

    int arrival_time[num_processes];
    int burst_time[num_processes];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter Arrival time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quantum);

    int remaining_time[num_processes];
    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = burst_time[i];
    }

    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (remaining_time[i] > 0) {
                int execute_time = (remaining_time[i] <= quantum) ? remaining_time[i] : quantum;
                remaining_time[i] -= execute_time;
                current_time += execute_time;

                if (remaining_time[i] == 0) {
                    completed_processes++;
                    int turnaround_time = current_time - arrival_time[i];
                    int waiting_time = turnaround_time - burst_time[i];

                    printf("Process %d\t%d\t%d\t%d\n", i + 1, burst_time[i], turnaround_time, waiting_time);

                    total_waiting_time += waiting_time;
                    total_turnaround_time += turnaround_time;
                }
            }
        }
    }

    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("\nAverage Turn Around Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}

