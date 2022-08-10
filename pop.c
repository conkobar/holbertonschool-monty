#include "monty.h"

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%D: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	if (tmp)
		(*stack)->next->prev = NULL;

	free(*stack);
	*stack = tmp;
}
