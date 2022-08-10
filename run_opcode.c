#include "monty.h"

void run_opcode(char *opcode, stack_t **stack, unsigned int line_num)
{
	int i;
	instruction_t opcode_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; opcode_list[i].opcode; i++)
	{
		if (strcmp(opcode_list[i].opcode, opcode) == 0)
		{
			opcode_list[i].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
