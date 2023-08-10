#include <stdio.h>

void sjf(int n, int processes[], int burst_time[], int arrival_time[]) {
    int WT[n], TAT[n], total_WT = 0, total_TAT = 0, completion_time = 0, total_idle = 0, RT[n];

    // Sort processes based on arrival time (for tie-breaking) and burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1] || (arrival_time[j] == arrival_time[j + 1] && burst_time[j] > burst_time[j + 1])) {
                int temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        completion_time = (completion_time > arrival_time[i] ? completion_time : arrival_time[i]) + burst_time[i];
        TAT[i] = completion_time - arrival_time[i];
        WT[i] = TAT[i] - burst_time[i];
        total_WT += WT[i];
        total_TAT += TAT[i];
        RT[i] = (arrival_time[i] > completion_time - burst_time[i] ? arrival_time[i] : completion_time - burst_time[i]);
        total_idle += (i == 0 ? arrival_time[i] : arrival_time[i] - completion_time);
    }

    printf("Processes\tAT\tBT\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], arrival_time[i], burst_time[i], WT[i], TAT[i], completion_time, RT[i]);
    }
    printf("AVG waiting time: %.2f\n", (float)total_WT / n);
    printf("AVG turnaround time: %.2f\n", (float)total_TAT / n);
    printf("Total Idle time: %d\n\n", total_idle);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n], burst_time[n], arrival_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and Burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        processes[i] = i + 1;
    }
    sjf(n, processes, burst_time, arrival_time);
    return 0;
}
