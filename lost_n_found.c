#include "monty.h"

/**
 * finders - find opcodes in file
 * @file: file to be scoured
 *
 * Return: 0 on success
 */
int finders(FILE *file)
{
	int keepers = 0;
	unsigned int line_number = 0;
	char *opcode = NULL;
	stack_t *stack = 0;
	size_t oplength = 0;

	while (getline(&opcode, &oplength, file) != -1)
	{
		line_number++;
		if (!strcmp(opcode, "\n"))
			continue;
		ops[0] = strtok(opcode, " \n\t");
		if (!ops[0] || ops[0][0] == '#')
			continue;
		ops[1] = strtok(NULL, " \n\t");
		losers(line_number, &stack);
	}
	if (fclose(file))
		exit(1);
	if (stack)
		freedumb(stack);
	if (opcode)
		free(opcode);
	return (keepers);
}

/**
 * losers - directs opcodes
 * @line_number: current line number of file
 * @stack: list of stack
 */
void losers(int line_number, stack_t **stack)
{
	unsigned int i;
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"pop", pop},
		{"nop", NULL},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (!strcmp(codes[i].opcode, ops[0]))
		{
			if (codes[i].f)
				codes[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ops[0]);
	exit(1);
}
