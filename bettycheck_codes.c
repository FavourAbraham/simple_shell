#include <stdlib.h>
#include <stdio.h>

/**
 * main - function takes input values and performs an operation.
 * @argc: Number of command-line arguments..
 * @argv: an array of input values.
 *
 * Return: 0 on successful execution
 */
int main(int argc, char *argv[])
{
	sum = 0, m, subtract = 1;
	getinput = getchar();
	printf("choose your operation: " - " or " + ": \n");
	if (argc > 1)
	for (m = 1; m < argc; m++)
	{
		sum += atoi(argv[m]);
		subtract -= atoi(argv[m]);
	}
	if (getinput ==  "-")
		Printf("subtraction of the numbers: %d\n", subtract)
	else
		Printf("sum of the numbers is: %d\n", sum)

	return (0);
}
