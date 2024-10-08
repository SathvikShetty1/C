#include<stdio.h>

int main() {
    int locks = 0, stocks = 0, barrels = 0, tlocks = 0, tstocks = 0, tbarrels = 0;
    float lprice = 45.0, sprice = 30.0, bprice = 25.0, sales = 0, comm;

    while (1) {
        printf("Enter locks (-1 to exit), stocks, and barrels: ");
        scanf("%d", &locks);
        if (locks == -1) break;
        scanf("%d%d", &stocks, &barrels);

        if (locks < 1 || locks > 70 || stocks < 1 || stocks > 80 || barrels < 1 || barrels > 90) {
            printf("Values out of range! Try again.\n");
            continue;
        }

        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;

        printf("Totals -> Locks: %d, Stocks: %d, Barrels: %d\n", tlocks, tstocks, tbarrels);
    }

    if (tlocks > 0 && tstocks > 0 && tbarrels > 0) {
        sales = tlocks * lprice + tstocks * sprice + tbarrels * bprice;
        printf("Total Sales: %.2f\n", sales);

        comm = (sales > 1800) ? (0.10 * 1000 + 0.15 * 800 + 0.20 * (sales - 1800)) :
               (sales > 1000) ? (0.10 * 1000 + 0.15 * (sales - 1000)) :
               (0.10 * sales);

        printf("Commission: %.2f\n", comm);
    } else {
        printf("No sales.\n");
    }

    return 0;
}
