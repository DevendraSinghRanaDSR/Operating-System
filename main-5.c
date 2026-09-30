#include <stdio.h>

int main() {
    int n;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int completed = 0, time = 0;
    int shortest;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // Remaining time initially equals burst time
    }

    while (completed != n) {
        shortest = -1;

        // Find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (shortest == -1 || rt[i] < rt[shortest]) {
                    shortest = i;
                }
            }
        }

        // If no process has arrived, move time forward
        if (shortest == -1) {
            time++;
            continue;
        }

        // Execute the selected process for 1 unit
        rt[shortest]--;
        time++;

        // If process is completed
        if (rt[shortest] == 0) {
            completed++;

            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            avg_tat += tat[shortest];
            avg_wt += wt[shortest];
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
