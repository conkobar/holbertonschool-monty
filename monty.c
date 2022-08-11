#include "monty.h"

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
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(1);
	}

	if (finders(file))
		exit(1);
	if (fclose(file))
		exit(1);
	if (ops[3])
		exit(1);

	return (0);
}
