#include <stdio.h>

void main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);

    for (i = 0; i < NOP; i++) {
        printf("\nEnter Arrival and Burst time of Process[%d]\nArrival time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter Time Quantum for processes: ");
    scanf("%d", &quant);

    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");

    for (sum = 0, i = 0, y = NOP; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= quant;
            sum += quant;
        }
        if (temp[i] == 0 && count == 1) {
            y--;
            printf("Process No[%d]\t%d\t\t%d\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i];
            tat += sum - at[i];
            count = 0;
        }
        i = (i == NOP - 1) ? 0 : i + 1;
        if (i == 0 || at[i] <= sum) {
            i = (i == NOP - 1) ? 0 : i + 1;
        } else {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\nAvg Turn Around Time: %f\n", avg_tat);
    printf("Avg Waiting Time: %f\n", avg_wt);
}
