#include <stdio.h>
#include <stdlib.h>

void FcfsDisk(int requests[], int n, int head) {
    int total_movement = 0;  // To store the total head movement

    printf("\nFCFS Disk Scheduling\n");
    printf("Request Order: %d", head);  // Print initial head position

    // Traverse each request in the order they arrived
    for (int i = 0; i < n; i++) {
        total_movement += abs(requests[i] - head);  // Calculate distance from current head to request
        head = requests[i];  // Move head to current request position
        printf(" -> %d", head); 
    }

    // Display total head movement
    printf("\n\nTotal Head Movement = %d cylinders\n", total_movement);
}

int main(){
  int requests[] = {12, 60, 183, 77, 91, 38};
  int n = sizeof(requests) / sizeof(requests[0]);

  int head = 45;

  FcfsDisk(requests, n, head);
  return 0;
}