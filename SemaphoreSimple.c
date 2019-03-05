#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#define N 10
/*
 * int sem_init(sem_t *sem, int pshared, unsigned int value);
 * 
 *	   The pshared argument indicates whether this semaphore is to be shared
 *     between the threads of a process, or between processes.
 *
 *     If pshared has the value 0, then the semaphore is shared between the
 *     threads of a process, and should be located at some address that is
 *     visible to all threads (e.g., a global variable, or a variable
 *     allocated dynamically on the heap).
 *
 *     If pshared is nonzero, then the semaphore is shared between
 *     processes, and should be located in a region of shared memory
 * 	   
 *     The value argument specifies the initial value for the semaphore.
 * 
*/

sem_t sem;

pthread_t tid[N];


void* doSomeThing(void *arg)
{
	sem_wait(&sem);
	printf("Inside Critical Section\n");
	sleep(rand()%5+1); // Thread is performing its job 
	sem_post(&sem);
    printf("Leaving Critical Section\n");

    return NULL;
}

int main(void)
{
    int i = 0,err,createdThreadCount=0;
	srand(time(NULL));   // should only be called once

	sem_init(&sem,0,0);

     for(i=0;i<N;i++){
        pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
		if (err == 0)
            createdThreadCount++;
    }


    //Threads are waiting for termination if not terminated
	for(i=0;i<N;i++)
		pthread_join(tid[i], NULL);


    return 0;
}
