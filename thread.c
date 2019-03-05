#include <pthread.h>
#include <stdio.h>

struct RunnerArgs {
   char *argsName;	
   int	number;
   int  associatedIndex;
};

int sum[3]; /* this data is shared by the thread(s) */

void *runner(void *params); /* the thread */

void main()
{
	struct 	RunnerArgs args1,args2,args3;

	pthread_t tid1,tid2,tid3; /* the thread identifier */
	pthread_attr_t attr; /* set of attributes for the thread */

	/* Arguments specifications */
	args1.argsName="Arguments 1";
	args1.number=200;
	args1.associatedIndex=0;

	args2.argsName="Arguments 2";
	args2.number=4;
	args2.associatedIndex=1;

	args3.argsName="Arguments 3";
	args3.number=10;
	args3.associatedIndex=2;

	/* get the default attributes */
	pthread_attr_init(&attr);

	/* create the threads */
	pthread_create(&tid1,&attr,runner,(void *)&args1);
	printf("tid1 is created\n");
	pthread_create(&tid2,&attr,runner,(void *)&args2);
	printf("tid2 is created\n");
	pthread_create(&tid3,&attr,runner,(void *)&args3);
	printf("tid3 is created\n");

	/* now wait for the thread to exit */
	pthread_join(tid1,NULL);
	printf("tid1 has joined\n");
	
	pthread_join(tid2,NULL);		
	printf("tid2 has joined\n");
	
	pthread_join(tid3,NULL);	
	printf("tid3 has joined\n");

	printf("sum0 = %d\nsum1 = %d\nsum2 = %d\n",sum[0],sum[1],sum[2]);
}

/**
 * The thread will begin control in this function
 */
void *runner(void *params) 
{
	struct RunnerArgs *args = (struct RunnerArgs *)params;
	int index = args -> associatedIndex;
	int upper = args -> number;
	char *argsName=	args -> argsName;
	int i;
	
	sum[index] = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum[index] += i*i;
	}
	printf("Argument = %s index = %d upper = %d (completed)\n",argsName,index,upper);
	pthread_exit(0);
}
