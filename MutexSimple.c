#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{
    pthread_mutex_lock(&lock);

    counter += 1;
    printf("Job %d started\n", counter);

    sleep(1); // We are performing a costly job.

    printf("Job %d finished\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    int i = 0;

    while(i < 2)
    {
        pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}
