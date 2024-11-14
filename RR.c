#include <stdio.h>

struct Process {
int id;
int burst_time;
int arrival_time;
int remaining_time;
int completion_time;
int waiting_time;
int turnaround_time;
};

void main()
{
int n, quantum;
struct Process p[10];

printf("Enter the number of processes: ");
scanf("%d", &n);

for (int i = 0; i < n; i++) {
p[i].id = i + 1;
printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
p[i].remaining_time = p[i].burst_time;
}

printf("Enter Time Quantum: ");
scanf("%d", &quantum);
int time = 0;
int completed = 0;

int i;

while (completed < n) {
int flag = 0;
for (i = 0; i < n; i++) {
if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {
flag = 1;
if (p[i].remaining_time > quantum) {
time += quantum;
p[i].remaining_time -= quantum;
} else {
time += p[i].remaining_time;
p[i].completion_time = time;
p[i].remaining_time = 0;
p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
completed++;

}
}
}
if (!flag) {
time++;
}
}
printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting
Time\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
p[i].id,

p[i].burst_time,
p[i].arrival_time,
p[i].completion_time,
p[i].turnaround_time,
p[i].waiting_time);
}
}
