#include <stdio.h>

struct Process {
    int id;
    int bt;  // Burst Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
};

void fcfs(struct Process p[], int n) {
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct; // Since Arrival Time = 0, TAT = CT
        p[i].wt = p[i].tat - p[i].bt;

        currentTime = p[i].ct;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    printf("\n--- FCFS Scheduling Results ---\n");
    printf("PID\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    fcfs(p, n);

    return 0;
}