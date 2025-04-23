#include <iostream>
using namespace std;

void FCFS(int at[], int bt[], int n) {
    int ct[n], tat[n], wt[n];
    
    // Calculate Completion Time (CT)
    ct[0] = at[0] + bt[0];
    for(int i=0; i<n; i++){
        cout << " p" << i+1 << "  ";
    }
    cout << endl;
    cout<< at[0] << "  ";
    cout << ct[0] << "  ";
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
        cout << ct[i] <<"    ";
    }
    cout << endl << endl;

    // Calculate Turn Around Time (TAT) = CT - AT
    for (int i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];

    // Calculate Waiting Time (WT) = TAT - BT
    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    // Print the result
    cout << "P#\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t"<< wt[i] << endl;
    }
}

int main() {
    int at[] = {0, 1, 2}; // Arrival Times
    int bt[] = {3, 16, 9}; // Burst Times
    int n = sizeof(bt) / sizeof(bt[0]);
    FCFS(at, bt, n);
    return 0;
}
