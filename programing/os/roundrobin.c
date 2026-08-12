#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int at;       // Arrival Time
    int bt;       // Burst Time
    int remaining_bt; 
    int priority; // Priority level
    int ct;       // Completion Time
    int tat;      // Turnaround Time
    int wt;       // Waiting Time
    bool isCompleted;
};

void priorityScheduling(struct Process p[], int n) {
    for (int i = 0; i < n; i++) p[i].isCompleted = false;

    int completed = 0, currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = 1e9; // Lower number means higher priority

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].isCompleted) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
                if (p[i].priority == highestPriority && p[i].at < p[idx].at) {
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
            currentTime++;
        }
    }

    printf("\n--- Priority (Non-Preemptive) Scheduling ---\n");
    printf("PID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
}

void roundRobin(struct Process p[], int n, int quantum) {
    int queue[100], front = 0, rear = 0;
    bool visited[100] = {false};

    int currentTime = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    // Initialize remaining burst times
    for (int i = 0; i < n; i++) {
        p[i].remaining_bt = p[i].bt;
    }

    // Sort by arrival time initially to handle queue insertion cleanly
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Push initial process
    queue[rear++] = 0;
    visited[0] = true;
    currentTime = p[0].at;

    while (front < rear) {
        int idx = queue[front++];

        if (p[idx].remaining_bt > quantum) {
            p[idx].remaining_bt -= quantum;
            currentTime += quantum;
        } else {
            currentTime += p[idx].remaining_bt;
            p[idx].remaining_bt = 0;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalWT += p[idx].wt;
            totalTAT += p[idx].tat;
            completed++;
        }

        // Add newly arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= currentTime) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }

        // If current process is not finished, re-enqueue it
        if (p[idx].remaining_bt > 0) {
            queue[rear++] = idx;
        }

        // If CPU is idle, pick next unvisited process
        if (front == rear && completed < n) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    currentTime = p[i].at;
                    queue[rear++] = i;
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    printf("\n--- Round Robin Scheduling (Quantum = %d) ---\n", quantum);
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p1[n], p2[n];
    for (int i = 0; i < n; i++) {
        p1[i].id = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process P%d: ", i + 1);
        scanf("%d %d %d", &p1[i].at, &p1[i].bt, &p1[i].priority);
        p2[i] = p1[i];
    }

    printf("Enter Time Quantum for Round Robin: ");
    scanf("%d", &quantum);

    priorityScheduling(p1, n);
    roundRobin(p2, n, quantum);

    return 0;
}