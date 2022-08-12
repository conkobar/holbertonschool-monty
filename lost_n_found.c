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
	unsigned int line_number = 1;
	char *opcode = NULL;
	stack_t *stack = 0;
	size_t oplength = 0;

	while (file)
	{
		keepers = getline(&opcode, &oplength, file);
		line_number++;
		if (keepers == -1)
			break;
		if (keepers == 1)
			continue;
		ops[0] = strtok(opcode, " \n\t");
		if (ops[0][0] == '#')
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
		{"nop", NULL},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (!strcmp(codes[i].opcode, ops[0]))
		{
			if (codes[i].f)
				codes[i].f(stack, line_number);
			break;
		}
	}
}
