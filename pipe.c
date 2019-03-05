#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void main()
{
	int pipefd[2];
	pid_t cpid;
	char buf;
	char *message="Hello World\n";
	char *message2 ="Pipe Example";


        if (pipe(pipefd) == -1) {
	        perror("pipe");
                exit(EXIT_FAILURE);
        }

        cpid = fork();
        if (cpid == -1) {
 	       perror("fork");
               exit(EXIT_FAILURE);
        }

	/* Child reads from pipe */
        if (cpid == 0) {    
              close(pipefd[1]);          /* Close unused write end */

              while (read(pipefd[0], &buf, 1) > 0)
	              write(STDOUT_FILENO, &buf, 1);

              write(STDOUT_FILENO, "\n", 1);
              close(pipefd[0]);
              _exit(EXIT_SUCCESS);

	} 
	/* Parent writes argv[1] to pipe */
	else {            
              close(pipefd[0]);          /* Close unused read end */
              write(pipefd[1], message, strlen(message));
	      sleep(2);
	      write(pipefd[1], message2, strlen(message2));	
              close(pipefd[1]);          /* Reader will see EOF */
              wait(NULL);                /* Wait for child */             
       }
}
