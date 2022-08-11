#include "monty.h"

char *ops[] = {
	NULL, NULL,
	"stack", NULL};
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
		errorlocus(1, 1);

	file = fopen(av[1], "r");

	if (!file)
	{

		errorlocus(2, 1);
	}

	if (finders(file))
		exit(1);

	if (fclose(file))
		exit(1);

	if (ops[3])
		exit(1);

	return (0);
}
