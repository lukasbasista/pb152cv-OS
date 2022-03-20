# 07

 1. In the exercise, we implemented a simple busy-waiting barrier.
 2. Let's do that again, but this time with a semaphore.
 3. You should create two files, ‹ssem.c› and ‹main.c›.
 4. In ‹ssem.c› (for spin semaphore), implement the following functions:
    - ‹ssem_init( int c )› which initializes the semaphore, ‹c› being the
       maximal number of threads to let in
    - ‹ssem_wait()› which waits for the semaphore
    - ‹ssem_post()› which unlocks the semaphore
    - there should «not» be a ‹main› function in ‹ssem.c›
    
 5. The global variables that you need should also live in ‹ssem.c›. Note that
    there is only a single global (spin) semaphore, not a data type and methods
    for this type. This is unlike ‹sem_t› from the standard library.
 6. In ‹main.c›, write a simple program that checks that semaphore works:
    - call ‹ssem_init()› so that 2 threads can enter at once
    - create 2 new (child) threads
    - all threads (including the main one) try to enter a critical section
    - the critical section is guarded by ‹ssem_wait›
    - each thread, upon getting into the critical section calls
       ‹in_critical()›
    - the function ‹in_critical()› simply prints a message to ‹stdout›
