#include "monty.h"

void run_opcode(char *opcode, stack_t **stack, unsigned int line_num)
{
	int i;
	instuction_t *opcode_list = OPCODES;

	for (i = 0; opcode_list[i].opcode; i++)
	{
		if (strcmp(opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(stack, line_num);
			return;
		}
	}

	frpintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}
