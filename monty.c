#include "monty.h"
/**
 * main - reads and translates monty files
 * @ac: arg count
 * @av: arg values
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL, *opcode = NULL;
	size_t size = 0;
	unsigned int line_num;
	stack_t *STACK = NULL, *tmp = NULL;
	FILE *fd;

	if (ac != 2)
		usage_error();

	fd = fopen(av[1], "r");
	if (!fd)
		file_error(av[1]);

	for (line_num = 1; (getline(&line, &size, fd)) != -1; line_num++)
	{
		if (*line == '\n')
			continue;

		opcode = strtok(line, " \t\n");

		if (!opcode)
			continue;

		arg.argument = strtok(NULL, " \t\n");
		run_opcode(opcode, &STACK, line_num);
	}

	free(line);

	if (STACK)
	{
		while (STACK)
		{
			tmp = STACK;
			STACK = tmp->next;
			free(tmp);
		}
	}

	fclose(fd);
	exit(EXIT_SUCCESS);
}
