#include <iostream>
using namespace std;

// Function to allocate memory using First Fit algorithm
void firstFitAllocation(int partitions[], int partitionAllocated[], int processes[], int nb, int np) {
    // Loop through each process to allocate memory
    for (int i = 0; i < np; i++) {
        int index = -1; // Index of the partition where current process will be allocated

        // Try to find the first suitable partition for the current process
        for (int j = 0; j < nb; j++) {
            // Check if partition is not already allocated and has enough space
            if (partitionAllocated[j] == 0 && partitions[j] >= processes[i]) {
                index = j;              // Allocate this partition
                partitionAllocated[j] = 1;       // Mark the partition as allocated
                break;                           // Stop searching after first fit
            }
        }

        // Output the result of allocation
        if (index != -1) {
            cout << "Process " << i + 1 << " allocated to partition of size " 
                 << partitions[index] << endl;
        } else {
            cout << "Process " << i + 1 << " cannot be allocated memory.\n";
        }
    }
}

int main() {
    // Number of memory partitions
    int nb = 5;

    // Sizes of each memory partition
    int partitions[] = {100, 500, 200, 300, 600};

    // Array to track whether a partition is allocated or not (0 = free, 1 = allocated)
    int partitionAllocated[5] = {0};  // Initially, all partitions are unallocated

    // Number of processes
    int np = 4;

    // Memory required by each process
    int processes[] = {212, 417, 112, 426};

    // Perform memory allocation using First Fit strategy
    firstFitAllocation(partitions, partitionAllocated, processes, nb, np);

    return 0;
}
