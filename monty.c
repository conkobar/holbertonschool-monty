#include "monty.h"
/**
 * opnfd -
 *
 */
int main(int ac, int **av)
{
	char *line = NULL, *opcode = NULL;
	size_t size = 0;
	unsigned int line_num;
	stack_t *STACK = NULL;
	FILE *fd;

	for (line_num = 1; (getline(&line, &size, fd)) != -1; line_num++)
	{
		if (line == '\n')
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
			temp = STACK;
			STACK = temp->next;
			free(temp);
		}
	}

	fclose(fd);
	exit(EXIT_SUCCESS);
}
