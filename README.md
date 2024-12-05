<b>
Producer-Consumer Problem with Semaphores

  
**Aim:**
Implement the classic Producer-Consumer synchronization problem using semaphores and threads.

Description:
The Producer-Consumer problem demonstrates inter-process communication and synchronization:

Producers create data and add to a shared buffer
Consumers remove and process data from the shared buffer
Semaphores ensure thread-safe access to the shared buffer

Algorithm

Create a fixed-size shared buffer
Use three semaphores:

empty: Tracks available empty slots
full: Tracks occupied buffer slots
mutex: Ensures mutual exclusion during buffer access


Producer thread:

Wait on empty semaphore
Acquire mutex
Add item to buffer
Release mutex
Signal full semaphore


Consumer thread:

Wait on full semaphore
Acquire mutex
Remove item from buffer
Release mutex
Signal empty semaphore


Output:
Produced: 0
Produced: 1
Consumed: 0
Produced: 2
Consumed: 1
Produced: 3
Consumed: 2
Produced: 4
Consumed: 3
Produced: 5
Consumed: 4
Produced: 6
Consumed: 5
Produced: 7
Consumed: 6
Produced: 8
Consumed: 7
Produced: 9
Consumed: 8
Consumed: 9
</b>
