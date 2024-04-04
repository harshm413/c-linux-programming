// Create a program using pthread create to generate multiple threads. 
// Each thread should display its unique ID and execution sequence.

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void* threadFunc(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread ID: %d, Execution Sequence: %d\n", thread_id, thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
