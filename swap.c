#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
				exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;

}
