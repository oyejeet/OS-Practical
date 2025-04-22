#include <iostream>
using namespace std;

// Function to perform Shortest Job First (SJF) Non-Preemptive Scheduling
void SJF_NonPreemptive(int at[], int bt[], int n) {
    int ct[n], tat[n], wt[n];        // Arrays for Completion Time, Turnaround Time, and Waiting Time
    int completed[n];
    // To track if a process is completed: (0 = not completed, 1 = completed)
    for (int i = 0; i < n; i++) {   
      completed[i] = 0;
    }
    int current_time = 0;            // Keeps track of the current time in the CPU
    int completed_count = 0;         // Counter for how many processes are completed

    // Loop until all processes are completed
    while (completed_count < n) {
        int idx = -1;                // Index of the next process to execute
        int min_bt = 9999;           // Minimum burst time, initialized to a large number

        // Find the process with the shortest burst time that has arrived and not yet completed
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && completed[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                } 
                // Tie-breaking rule: if burst times are equal, choose the one with earlier arrival time
                else if (bt[i] == min_bt && at[i] < at[idx]) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // If a process is found, calculate its completion time
            ct[idx] = current_time + bt[idx];
            current_time = ct[idx];          // Move current time forward
            completed[idx] = 1;              // Mark process as completed
            completed_count++;               // Increment count of completed processes
        } else {
            current_time++; // If no process is ready, increment time (CPU idle)
        }
    }

    // Calculate Turnaround Time and Waiting Time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];      // TAT = Completion Time - Arrival Time
        wt[i] = tat[i] - bt[i];      // WT = Turnaround Time - Burst Time
    }

    // Print the final results
    cout << "P#\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" 
             << at[i] << "\t" 
             << bt[i] << "\t" 
             << ct[i] << "\t" 
             << tat[i] << "\t" 
             << wt[i] << endl;
    }
}

int main() {
    // Sample input: Arrival Time and Burst Time for 3 processes
    int at[] = {0, 1, 2};     // Arrival Times
    int bt[] = {7, 4, 1};     // Burst Times
    int n = sizeof(at) / sizeof(at[0]);  // Number of processes

    // Call the scheduling function
    SJF_NonPreemptive(at, bt, n);

    return 0;
}
