#include <iostream>
#define MAX 100
using namespace std;

// Function to perform Round Robin Scheduling
void RoundRobin(int at[], int bt[], int n, int tq) {
    int rt[MAX] = {0}, wt[MAX] = {0}, tat[MAX] = {0}, complete[MAX] = {0};
    int time = 0, remain = n, flag = 0;
    // Initialize remaining time array with burst time
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    cout << "\nP\tAT\tBT\tTAT\tWAT\n";

    // Run until all processes are completed
    while (remain != 0) {
        flag = 1; // Used to check if any process was ready in this cycle

        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and has remaining burst time
            if (at[i] <= time && rt[i] > 0) {
                flag = 0; // At least one process is ready

                if (rt[i] <= tq) {
                    // Process will finish in this cycle
                    time += rt[i];
                    rt[i] = 0;
                    complete[i] = 1; // Mark as complete
                } else {
                    // Process will not finish in this cycle
                    rt[i] -= tq;
                }

                // If the process has just completed, calculate TAT and WT
                if (complete[i] == 1 && tat[i] == 0) {
                    tat[i] = time - at[i];       // Turnaround Time = Completion - Arrival
                    wt[i] = tat[i] - bt[i];       // Waiting Time = Turnaround - Burst

                    // Display the result for this process
                    cout << "P" << i + 1 << "\t"<< 
                    at[i] <<"\t" 
                    << bt[i] <<"\t" 
                    << tat[i] <<"\t" 
                    << wt[i] << endl;

                    remain--; // Decrease the remaining process count
                }
            }
        }

        // If no process was ready, move the time forward
        if (flag == 1) {
            time++;
        }
    }

}

int main() {
  int at[] = {0, 1, 2};
  int bt[] = {2, 3, 1};
  int tq = 5;
  int n = sizeof(bt) / sizeof(bt[0]); 

    // Call the Round Robin scheduling function
    RoundRobin(at, bt, n, tq);

    return 0;
}
