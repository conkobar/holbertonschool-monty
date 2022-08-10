#include "monty.h"

int main(int ac, char **av)
{
	FILE *fd = fopen(av[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fd);
		exit(EXIT_FAILURE);
	}

	return (0);
}
