#include<stdio.h>
int main() {
    int locks, stocks, barrels, tlocks = 0, tstocks = 0, tbarrels = 0; 
    float sales = 0, comm;
    while (1) {
        printf("Enter locks, stocks, barrels (-1 to exit): ");
        scanf("%d", &locks);
        if (locks == -1) break;
        scanf("%d%d", &stocks, &barrels);
        if (locks <= 0 || locks > 70 || stocks <= 0 || stocks > 80 || barrels <= 0 || barrels > 90) {
            printf("Input out of range!\n");
            continue;
        }
        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;
    }
    sales = tlocks * 45.0 + tstocks * 30.0 + tbarrels * 25.0;
    comm = (sales > 1800) ? 0.1 * 1000 + 0.15 * 800 + 0.2 * (sales - 1800) : 
           (sales > 1000) ? 0.1 * 1000 + 0.15 * (sales - 1000) : 0.1 * sales;
    printf("Total Locks: %d, Total Stocks: %d, Total Barrels: %d\n", tlocks, tstocks, tbarrels);
    printf("Total Sales: %.2f, Commission: %.2f\n", sales, comm);
    return 0;
}
