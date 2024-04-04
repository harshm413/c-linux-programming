// Create a threaded application that demonstrates graceful 
// thread termination using pthread exit for resource 
// cleanup compared to abrupt termination via pthread_cancel.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void* arg) {
    printf("Thread: Performing work...\n");
    sleep(2);
    printf("Thread: Cleaning up resources...\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, threadFunc, NULL);

    sleep(1);

    pthread_cancel(thread);

    printf("Thread canceled.\n");

    return 0;
}
