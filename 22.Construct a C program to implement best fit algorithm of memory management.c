#include <stdio.h>

#define MAX_BLOCKS 10

// Function to allocate memory using Best Fit Algorithm
void best_fit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int best_fit_index = -1;
        int min_fragment = MAX_BLOCKS + 1;

        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (blockSize[j] - processSize[i] < min_fragment) {
                    min_fragment = blockSize[j] - processSize[i];
                    best_fit_index = j;
                }
            }
        }

        if (best_fit_index != -1) {
            blockSize[best_fit_index] -= processSize[i];
            allocation[i] = best_fit_index;
        } else {
            printf("Memory allocation failed: No suitable block found\n");
        }
    }

    // Print the memory allocation table
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_BLOCKS];
    int m, n, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    best_fit(blockSize, m, processSize, n);

    return 0;
}
