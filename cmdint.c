#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * display_mypromt - Displays the prompt.
 *
**/

void display_mypromt(void)
{
	printf("Oursimple_shell#");
	fflush(stdout);
}

/**
 * execute_input - Executes commands
 *
 * @input: Takes command
 *
 * Return: 1 in execution
**/

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

/**
 * main -  Execute command, reads command and prints new line.
 *
 * Return: 0 after executing
**/

int main(void) /* Entry point*/
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

