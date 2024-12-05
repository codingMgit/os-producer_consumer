<b>
Producer-Consumer Problem with Semaphores
Aim
Implement the classic Producer-Consumer synchronization problem using semaphores and threads.
Description
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
</b>
