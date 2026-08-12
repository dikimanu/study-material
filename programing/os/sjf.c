#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
    bool isCompleted;
};

void sjf(struct Process p[], int n) {
    for (int i = 0; i < n; i++) p[i].isCompleted = false;

    int completed = 0, currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        // Find process with shortest burst time among those that have arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].isCompleted) {
                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
                if (p[i].bt == minBT && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].ct = currentTime + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].isCompleted = true;

            currentTime = p[idx].ct;
            totalWT += p[idx].wt;
            totalTAT += p[idx].tat;
            completed++;
        } else {
            currentTime++; // CPU is idle
        }
    }

    printf("\n--- SJF Scheduling Results ---\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
}

int main() {
    int n;
    printf("Enter number of processes for SJF: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sjf(p, n);

    return 0;
}