#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
    int pid;          // Process ID
    int arrival_time; // Arrival Time
    int burst_time;   // Burst Time
    int priority;     // Priority (Lower value = Higher priority)
    int remaining_time;
    int completion_time;
    int turnaround_time; // TAT = Completion Time - Arrival Time
    int waiting_time;    // WT = Turnaround Time - Burst Time
};

void calculateTimes(struct Process proc[], int n) {
    int completed = 0;
    int current_time = 0;
    int total_wt = 0, total_tat = 0;

    // Initialize remaining time for each process
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
    }

    while (completed != n) {
        int highest_priority_idx = -1;
        int highest_priority = INT_MAX;

        // Find process with highest priority among arrived processes
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].remaining_time > 0) {
                if (proc[i].priority < highest_priority) {
                    highest_priority = proc[i].priority;
                    highest_priority_idx = i;
                }
                // Tie-breaker: process that arrived earlier gets preference
                else if (proc[i].priority == highest_priority) {
                    if (proc[highest_priority_idx].arrival_time > proc[i].arrival_time) {
                        highest_priority_idx = i;
                    }
                }
            }
        }

        // If no process is ready at current_time, advance clock
        if (highest_priority_idx == -1) {
            current_time++;
        } else {
            // Execute the process for 1 unit of time
            proc[highest_priority_idx].remaining_time--;
            current_time++;

            // Check if process has finished execution
            if (proc[highest_priority_idx].remaining_time == 0) {
                completed++;
                
                // Completion Time (CT)
                proc[highest_priority_idx].completion_time = current_time;
                
                // Turnaround Time (TAT) = CT - AT
                proc[highest_priority_idx].turnaround_time = 
                    proc[highest_priority_idx].completion_time - proc[highest_priority_idx].arrival_time;
                
                // Waiting Time (WT) = TAT - BT
                proc[highest_priority_idx].waiting_time = 
                    proc[highest_priority_idx].turnaround_time - proc[highest_priority_idx].burst_time;

                total_tat += proc[highest_priority_idx].turnaround_time;
                total_wt += proc[highest_priority_idx].waiting_time;
            }
        }
    }

    // Display Process Output Table
    printf("\n=========================================================================\n");
    printf("PID\tArrival\tBurst\tPriority\tCompletion\tTAT\tWaiting\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
               proc[i].pid, 
               proc[i].arrival_time, 
               proc[i].burst_time,
               proc[i].priority, 
               proc[i].completion_time,
               proc[i].turnaround_time, 
               proc[i].waiting_time);
    }
    printf("=========================================================================\n");

    // Display Averages
    printf("\nAverage Turnaround Time (Avg TAT) = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time (Avg WT)    = %.2f\n", (float)total_wt / n);
}

int main() {
    int n;

    // User Input for number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // User Input for each process details
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("\n--- Process P%d ---\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Enter Priority (lower number = higher priority): ");
        scanf("%d", &proc[i].priority);
    }

    calculateTimes(proc, n);

    return 0;
}