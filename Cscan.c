#include<stdio.h>
#include<stdlib.h>

int main() {
    int rq[100], n, totalheadmovement = 0, initial, size, move;
    printf("Enter the no of requests:\n");
    scanf("%d", &n);
    printf("Enter the request sequence\n");
    for (int i = 0; i < n; i++) scanf("%d", &rq[i]);
    printf("Enter the initial head position\n");
    scanf("%d", &initial);
    printf("Enter the total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (rq[j] > rq[j + 1]) {
                int temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }

    int index = 0;
    for (int i = 0; i < n; i++)
        if (initial < rq[i]) {
            index = i;
            break;
        }

    printf("Sequence of request access:\n");
    for (int i = index; i < n; i++) {
        printf("%d ", rq[i]);
        totalheadmovement += abs(rq[i] - initial);
        initial = rq[i];
    }

    totalheadmovement += abs(size - rq[n - 1] - 1);
    totalheadmovement += abs(size - 1);
    initial = 0;
    for (int i = 0; i < index; i++) {
        printf("%d ", rq[i]);
        totalheadmovement += abs(rq[i] - initial);
        initial = rq[i];
    }

    if (move == 0) {
        totalheadmovement += abs(rq[0] - 0);
        totalheadmovement += abs(size - 1 - rq[index - 1]);
        initial = size - 1;
        for (int i = n - 1; i >= index; i--) {
            printf("%d ", rq[i]);
            totalheadmovement += abs(rq[i] - initial);
            initial = rq[i];
        }
    }
    
    printf("\nTotal head movement is %d\n", totalheadmovement);
    return 0;
}
