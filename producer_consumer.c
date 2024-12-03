#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

// Shared buffer
int buffer[BUFFER_SIZE];
int in = 0;  // Points to the next empty slot in the buffer
int out = 0; // Points to the next full slot in the buffer

// Semaphores
sem_t empty, full, mutex;

void *producer(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty); // Decrease the empty slot count
        sem_wait(&mutex); // Enter critical section

        // Produce an item
        buffer[in] = i;
        printf("Produced: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE; // Move to the next slot

        sem_post(&mutex); // Exit critical section
        sem_post(&full);  // Increase the full slot count
    }
    return NULL;
}

void *consumer(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);  // Decrease the full slot count
        sem_wait(&mutex); // Enter critical section

        // Consume an item
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; // Move to the next slot

        sem_post(&mutex); // Exit critical section
        sem_post(&empty); // Increase the empty slot count
    }
    return NULL;
}

int main()
{
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE); // Initially, all slots are empty
    sem_init(&full, 0, 0);            // Initially, no items are in the buffer
    sem_init(&mutex, 0, 1);           // Mutex for critical section, initially unlocked

    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
