#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char input;

	prinf("shell$")
	fflush(stdout);
	if(fgets(input, sizeof(input), stdin) == NULL)
	{
		printf("\n")
		break;
	}
	input[strpsn(input, "\n")] = "\0";
	
	pid_t Mypid = fork();
	if (Mypid == -1)
	{
		perror("fork")
		exit(EXIT_FAILURE);
	}
	else if (Mypid == 0)
	{
		char *argk[] = {input, NULL};
		execve(input, argk, NULL);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else 
	{
		int Parent;
		waitpid(Mypid, &Parent, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			printf("Sorry: Command failed\n");
	}
	print ("Exit shell\n");

}

