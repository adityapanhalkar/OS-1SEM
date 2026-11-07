#include <stdio.h>

int main(void) {
    int n, bt[20], rem[20], wt[20], tat[20];
    int tq, time = 0, done, i;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    if (tq <= 0) {
        printf("Invalid time quantum.\n");
        return 1;
    }

    do {
        done = 1;

        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\n", avgwt / n);
    printf("Average TAT = %.2f\n", avgtat / n);

    return 0;
}
