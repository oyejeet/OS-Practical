#include<stdio.h> 
#include<stdlib.h> 

// Global semaphore and buffer variables
int mutex = 1;    // Binary semaphore for mutual exclusion (initially unlocked)
int full = 0;     // Counter to track number of full slots (initially 0)
int empty = 3;    // Counter to track number of empty slots (buffer size = 3)
int x = 0;        // 'x' will store item number produced or consumed

// wait() function - simulates wait (P) operation on semaphore
int wait(int s) {  
    return (--s); // Decrement semaphore value and return it
}  

// signal() function - simulates signal (V) operation on 4semaphore
int signal(int s) {  
    return (++s); // Increment semaphore value and return it
}  

// producer() function - to produce an item
void producer() {  
    mutex = wait(mutex);  // Acquire lock (mutex--)
    full = signal(full);  // Increase count of full slots (full++)
    empty = wait(empty);  // Decrease count of empty slots (empty--)
    x++;                 // Increment item number
    printf("Producer produces the item %d\n", x);  // Print produced item
    mutex = signal(mutex); // Release lock (mutex++)
}  

// consumer() function - to consume an item
void consumer() {  
    mutex = wait(mutex);  // Acquire lock (mutex--)
    full = wait(full);    // Decrease count of full slots (full--)
    empty = signal(empty); // Increase count of empty slots (empty++)
    printf("Consumer consumes item %d\n", x);  // Print consumed item
    x--;               // Decrement item number
    mutex = signal(mutex); // Release lock (mutex++)
}  

// main() function - program starts from here
int main() {  
    int n;  // User choice input

    printf("\n1. Producer\n2. Consumer\n3. Exit"); // Menu display

    while(1) {  // Infinite loop until user exits
        printf("\nEnter your choice: ");  
        scanf("%d", &n);  // Read user's choice

        switch(n) {  // Switch-case based on user's choice
            case 1:  // Choice 1 - Producer
                if((mutex == 1) && (empty != 0))  // If mutex is free and buffer not full
                    producer();  // Call producer function
                else  
                    printf("Buffer is full!!\n"); // Cannot produce if buffer is full
                break;  

            case 2:  // Choice 2 - Consumer
                if((mutex == 1) && (full != 0))  // If mutex is free and buffer not empty
                    consumer();  // Call consumer function
                else  
                    printf("Buffer is empty!!\n"); // Cannot consume if buffer is empty
                break;  

            case 3:  // Choice 3 - Exit
                exit(0);  // Terminate the program
                break;  
        }  
    }  
    return 0;  // Return 0 to indicate normal program termination
}