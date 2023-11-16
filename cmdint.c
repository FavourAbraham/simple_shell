#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * main: The main Proram.
 *
 * execute_input: It executes command.
 *
 * display_mypromt: Displays promt.
 *
 *
 */

void display_mypromt(void)
{
	printf("Oursimple_shell#");
	fflush(stdout);
}

int execute_input(char *input)
{
	pid_t pid;
	int parent;

	pid = fork();

	if  (pid == 0)
	{
		char *argk[] = {NULL, NULL};
		argk[0] = input;

		if (execve(input, argk, NULL) == -1)
		{
			perror("failed_input");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("shell_failed");
	else
	{
	do {	pid = waitpid(pid, &parent, WUNTRACED);
	} while (!WIFEXITED(parent) && !WIFSIGNALED(parent));
	}
	return (1);
}
int main(void)
{
	char *input = NULL;
	size_t lon = 0;
	ssize_t read;

	while (1)
	{
		display_mypromt();
		read = getline(&input, &lon, stdin);

		if (read == -1)
		{
			printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (read > 1)
		{
			input[read - 1] = '\0';

		if (execute_input(input) == 0)
			break;
		}
	}

	free(input);
	return (0);
}

