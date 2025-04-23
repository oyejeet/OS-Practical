#include <iostream>
#define MAX 20
using namespace std;

// Function to implement Shortest Remaining Time First (SRTF) Scheduling
void SRTF(int at[], int bt[], int n) {
    int rt[MAX]={0}, wt[MAX] = {0}, tat[MAX] = {0}; // Arrays for Remaining Time, Waiting Time, and Turnaround Time
    int smallest=0, count = n, time = 0;
    int total_wt = 0, total_tat = 0;

    // Copy Burst Time to Remaining Time array
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    // Sentinel value to handle comparison when no valid process is found
    rt[MAX - 1] = 9999;

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n";

    // Run loop until all processes are completed
    while (count != 0) {
        smallest = MAX - 1;

        // Find the process with the shortest remaining time among those that have arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }

        // Execute the selected process for 1 unit of time
        rt[smallest]--;
        time++;

        // If the process has completed
        if (rt[smallest] == 0) {
            count--; // One less process to complete
            tat[smallest] = time - at[smallest];           // Turnaround Time = Completion - Arrival
            wt[smallest] = tat[smallest] - bt[smallest];  // Waiting Time = TAT - Burst

            // Accumulate total WT and TAT for average calculation
            total_tat += tat[smallest];
            total_wt += wt[smallest];

            // Print details for the process
            cout << "P" << smallest + 1 << "\t"
                 << at[smallest] << "\t"
                 << bt[smallest] << "\t"
                 << time << "\t\t"
                 << tat[smallest] << "\t"
                 << wt[smallest] << endl;
        }
    }

    // Calculate and print average waiting and turnaround times
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    cout << "\nAverage Waiting Time: " << avg_wt;
    cout << " ms\nAverage Turnaround Time: " << avg_tat << " ms" << endl;
}

int main() {
    // Arrival and Burst times for processes
    int at[MAX] = {0, 2, 4, 6}; // Arrival times
    int bt[MAX] = {8, 4, 2, 1}; // Burst times
    int n = 4; // Number of processes

    // Run SRTF Scheduling
    SRTF(at, bt, n);

    return 0;
}
