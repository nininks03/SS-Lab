#include <stdio.h>
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
void calculateTimes(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    int is_completed[n];
    for (int i = 0; i < n; i++) is_completed[i] = 0;  // Initialize all processes as incomplete
    while (completed < n) {
        int idx = -1;
        int min_burst = 10000;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !is_completed[i] && p[i].burst_time < min_burst) {
                min_burst = p[i].burst_time;
                idx = i;
            }
        }
        if (idx != -1) {
            current_time += p[idx].burst_time;
            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            is_completed[idx] = 1;
            completed++;
        } else {
            current_time++;
        }
    }
}
void printProcesses(struct Process p[], int n) {
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }
    calculateTimes(p, n);
    printProcesses(p, n);
    return 0;
}
