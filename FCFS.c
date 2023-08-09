#include <stdio.h>

void fcfs(int n, int processes[], int burst_time[], int arrival_time[]) {
    int WT[n], TAT[n], total_WT = 0, total_TAT = 0, completion_time = 0, total_idle = 0, RT[n];

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
    fcfs(n, processes, burst_time, arrival_time);
    return 0;
}
/*
Enter the number of processes: 5
Enter the arrival time and Burst time for process 1: 0 3
Enter the arrival time and Burst time for process 2: 1 6
Enter the arrival time and Burst time for process 3: 2 4
Enter the arrival time and Burst time for process 4: 3 5
Enter the arrival time and Burst time for process 5: 4 2
Processes    AT    BT    WT    TAT    CT    RT
1            0     3     0     3      3     0
2            1     6     3     9      12    2
3            2     4     6     10     16    4
4            3     5     10    15     21    5
5            4     2     15    17     23    7
AVG waiting time: 6.80
AVG turnaround time: 10.80
Total Idle time: 0
*/
