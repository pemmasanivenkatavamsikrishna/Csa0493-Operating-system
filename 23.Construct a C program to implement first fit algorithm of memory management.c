#include <stdio.h>

#define MAX_MEMORY_SIZE 1000

// Structure to represent a memory block
typedef struct {
    int size;
    int allocated;
} MemoryBlock;

// Function to allocate memory using First Fit Algorithm
void first_fit(MemoryBlock memory[], int num_blocks, int process_size) {
    // Find the first memory block that can accommodate the process
    for (int i = 0; i < num_blocks; i++) {
        if (memory[i].size >= process_size && !memory[i].allocated) {
            memory[i].allocated = 1;
            printf("Memory allocated successfully at block %d\n", i);
            return;
        }
    }

    // If no suitable block is found, print an error message
    printf("Memory allocation failed: No suitable block found\n");
}

int main() {
    // Initialize memory blocks and process size
    MemoryBlock memory[] = {{100, 0}, {200, 0}, {300, 0}};
    int num_blocks = sizeof(memory) / sizeof(memory[0]);
    int process_size = 150;

    // Call first_fit function to allocate memory using First Fit Algorithm
    first_fit(memory, num_blocks, process_size);

    return 0;
}
