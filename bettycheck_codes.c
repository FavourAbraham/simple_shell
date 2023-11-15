#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

/**
 * main - function takes input values and performs an operation.
 * @argc: Number of command-line arguments..
 * @argv: an array of input values.
 *
 * Return: 0 on successful execution
 */
int main(int argc, char *argv[])
{
	char getinput[MAX_LENGTH];
	int sum;
	int m;
	int subtract;
	sum = 0;
	subtract = 1;
	getinput[0] = getchar();
	printf("choose your operation: %c or %c:\n", '+', '-');
	if (argc > 1)
	for (m = 1; m < argc; m++)
	{
		sum += atoi(argv[m]);
		subtract -= atoi(argv[m]);
	}
	if (strcmp(getinput, "-") == 0)
		printf("subtraction of the numbers: %d\n", subtract);
	else
		printf("sum of the numbers is: %d\n", sum);

	return (0);
}
