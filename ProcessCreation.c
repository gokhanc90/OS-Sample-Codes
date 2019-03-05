#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

int  main(void)
{
     pid_t  pid, terminatedChildPid;

     /* fork a child process */
     pid=fork();
     if(pid<0) {
     	printf("Fork Failed!\n");
	return 1;
     }
     /* Child Process */
     else if(pid==0){
        printf("Child pid: %d\n", pid);
     	execlp("/bin/ls","ls","-al",NULL);
     }
     /* Parent Process */
     else {
	printf("Parent pid: %d\n", pid);
	terminatedChildPid=wait(NULL);
     	printf("Child Complete (pid: %d)\n",terminatedChildPid);
     }
     return 0;
}
