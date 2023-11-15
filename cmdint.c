#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define LENGTH 50

/*
 * main : Start of the program.
 *
 * Return: 0 on success.
*/

int main(void)
{
	char input[LENGTH];
	pid_t Mypid = fork();

	printf("shell$");
	fflush(stdout);
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		printf("\n");
	}
	input[strspn(input, "\n")] = '\0';

	if (Mypid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (Mypid == 0)
	{
		char *argk[2];
		argk[0] = input;
		argk[1] = NULL;
		execve(input, argk, NULL);

		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		int Parent;
		waitpid(Mypid, &Parent, 0);

		if (WIFEXITED(Parent) && WEXITSTATUS(Parent) != 0)
			printf("Sorry: Command failed\n");
	}
	printf ("Exit shell\n");
	return (0);
}

