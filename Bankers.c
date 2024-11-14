#include <stdio.h>

int main() {
    int n, m, i, j, k;
    
    // Input for number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);
    
    int allocation[n][m], maximum[n][m], available[m], need[n][m];
    int finish[n], safeSequence[n];
    
    // Initialize finish array to 0 (all processes are not finished initially)
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Input Allocation Matrix
    printf("Enter the allocation matrix for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    // Input Maximum Matrix
    printf("Enter the maximum matrix for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);
    }

    // Input Available Resources
    printf("Enter the available resources: ");
    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);

    // Calculate Need Matrix
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            need[i][j] = maximum[i][j]-allocation[i][j];
        }
    }
    printf("The need matrix is :-\n");
    for(i=0;i<n;i++) {
        printf("P%d : ",i);
        for(j=0;j<m;j++) {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    // Banker's Algorithm: Find Safe Sequence
    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) { // Process not yet finished
                int canProceed = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canProceed = 0; // Can't proceed, need exceeds available
                        break;
                    }
                }
                if (canProceed) {
                    // Process can proceed, update available resources
                    for (k = 0; k < m; k++)
                        available[k] += allocation[i][k];
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    // If system is in a safe state, display Safe Sequence
    printf("\nSystem is in a safe state.\nSafe Sequence is: ");
    for (i = 0; i < n-1; i++)
        printf("P%d -> ", safeSequence[i]);
    printf("P%d ", safeSequence[i]);
    printf("\n");
    
    return 0;
}
