#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ARRAY_SIZE 10

// Thread function to calculate average
void *calculateAverage(void *arg) {
    int *numbers = (int *)arg;
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += numbers[i];
    }
    double *average_ptr = (double *)malloc(sizeof(double));
    *average_ptr = sum / ARRAY_SIZE;
    pthread_exit((void *)average_ptr);
}

// Thread function to calculate maximum
void *calculateMaximum(void *arg) {
    int *numbers = (int *)arg;
    int max_val = numbers[0];
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }
    int *maximum_ptr = (int *)malloc(sizeof(int));
    *maximum_ptr = max_val;
    pthread_exit((void *)maximum_ptr);
}

// Thread function to calculate minimum
void *calculateMinimum(void *arg) {
    int *numbers = (int *)arg;
    int min_val = numbers[0];
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
    }
    int *minimum_ptr = (int *)malloc(sizeof(int));
    *minimum_ptr = min_val;
    pthread_exit((void *)minimum_ptr);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int numbers[ARRAY_SIZE] = {10, 5, 7, 8, 3, 15, 12, 6, 9, 20};
    double average;
    int maximum, minimum;

    // Create threads for each statistical operation
    pthread_create(&threads[0], NULL, calculateAverage, (void *)numbers);
    pthread_create(&threads[1], NULL, calculateMaximum, (void *)numbers);
    pthread_create(&threads[2], NULL, calculateMinimum, (void *)numbers);

    // Wait for all threads to finish and retrieve results
    void *result;
    pthread_join(threads[0], &result);
    average = *(double *)result;
    free(result);

    pthread_join(threads[1], &result);
    maximum = *(int *)result;
    free(result);

    pthread_join(threads[2], &result);
    minimum = *(int *)result;
    free(result);

    // Print statistical results
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);

    return 0;
}