#include "monty.h"

char *ops[] = {NULL, NULL, NULL, NULL};
/**
 * main - simple monty file processor
 * @ac: arg count
 * @av: arg values
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}

	file = fopen(av[1], "r");

	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(1);
	}

	if (finders(file))
		exit(1);

	return (0);
}
