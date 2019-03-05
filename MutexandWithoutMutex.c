#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define N 30000
pthread_t tid[N];
int counter=0;
pthread_mutex_t lock;

void* countWithMutex(void *arg)
{
    pthread_mutex_lock(&lock);

    counter += 1;
    
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* countWithoutMutex(void *arg)
{ 
    counter += 1;
     
    return NULL;
}

int main(void)
{
    int i,err,createdThreadCount=0;
	
	// With Mutex	
	//Threads are creating
    for(i=0;i<N;i++){
        pthread_create(&(tid[i]), NULL, &countWithMutex, NULL);
		if (err == 0)
            createdThreadCount++;
    }
    //Threads are waiting for termination if not terminated
	for(i=0;i<N;i++)
		pthread_join(tid[i], NULL);

	printf("Counter should be %d\n",createdThreadCount);
	printf("Counter is %d\n",counter);
	
    //=================================
    i=0;
    counter=0;
    createdThreadCount=0;
    // Without Mutex	
	//Threads are creating
    for(i=0;i<N;i++){
        pthread_create(&(tid[i]), NULL, &countWithoutMutex, NULL);
		if (err == 0)
            createdThreadCount++;
    }
    //Threads are waiting for termination if not terminated
	for(i=0;i<N;i++)
		pthread_join(tid[i], NULL);

	printf("============================\n");
	printf("Counter should be %d\n",createdThreadCount);
	printf("Counter is %d\n",counter);
    
    return 0;
}
