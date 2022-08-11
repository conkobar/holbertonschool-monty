#include "monty.h"

/**
 * findops - find opcodes in file
 * @file: file to be scoured
 *
 * Return: 0 on success
 */
int finders(FILE *file)
{
	int i, keepers;
	unsigned int line_number = 1;
	char *opcode;
	stack_t *stack;
	size_t oplength = 0;

	while (keepers = getline(&opcode, &oplength, file))
	{
		line_number++;

		if (keepers == -1)
			break;

		if (keepers == 1)
			continue;

		for (i = 0; opcode[i]; i++)
		{
			if (opcode[i] == (' ' || '\t'))
				keepers = 0;
			else
				break;
		}

		if (!keepers)
			continue;

		ops[0] = strtok(opcode, " \n\t");

		if (!ops[0])
			ops[0] = strtok(NULL, " \n\t");

		if (ops[0][0] == '#');
			continue;

		ops[1] = strtok(NULL, " \n\t");
		losers(line_number, &stack);
		if (ops[3])
			break;
	}

	if (stack)
		freedumb(stack);

	if (opcode)
		free(opcode);

	return (0);
}

/**
 * losers - directs opcodes
 * line_number: current line number of file
 * stack: list of stack
 */
void losers(int line_number, stack_t **stack)
{
	unsigned int i, weepers;
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
			if (ops[3])
				return;
			weepers = 1;
			break;
		}
	}

	if (!weepers)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, ops[0]);
		ops[3] = "weepers";
		return;
	}
}
