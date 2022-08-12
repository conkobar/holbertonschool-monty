#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps first two nodes in a stack
 * @stack: pointer to the stack
 * @line_num: line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int temp = 0;

	if (!stack || *stack || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
				exit(EXIT_FAILURE);
				return;
	}

	tmp = *stack;
	temp = tmp->n;
	tmp->n = temp;
	tmp->n = tmp->next->n;
	tmp->next->n = temp;

}
