#include <stdio.h>
#define N 5  // Number of philosophers and chopsticks
int chopstick[N] = {0};  // 0 = free, 1 = taken

// Function to simulate wait
int wait(int i) {
    if (chopstick[i] == 0) {
        chopstick[i] = 1;  // Take chopstick
        return 1;          // Success
    }
    return 0;              // Failed to take chopstick
}

// Function to simulate signal
void signal(int i) {
    chopstick[i] = 0;  // Release chopstick
}

int main() {
    for (int i = 0; i < N; i++) {
        printf("Philosopher %d is trying to eat...\n", i);

        // Try to pick up both left and right chopsticks
        if (wait(i) && wait((i + 1) % N)) {
            printf("Philosopher %d is eating using chopsticks %d and %d.\n", i, i, (i + 1) % N);

            // After eating, put down both chopsticks
            signal(i);
            signal((i + 1) % N);

            printf("Philosopher %d finished eating and is now thinking.\n", i);
        } else {
            // Couldn't eat because one of the chopsticks is busy
            printf("Philosopher %d couldn't eat (one or both chopsticks busy).\n", i);

            // If one chopstick was picked, release it
            if (chopstick[i] == 1) signal(i);
            if (chopstick[(i + 1) % N] == 1) signal((i + 1) % N);
        }

        printf("\n");
    }

    return 0;
}