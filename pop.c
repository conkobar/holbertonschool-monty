#include "monty.h"

/**
 * pop - remove the top member of the stack
 * @stack: struct representing the stack
 * @line_number: line count
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	if (tmp)
		(*stack)->next->prev = NULL;

	free(*stack);
	*stack = tmp;
}
