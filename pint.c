#include "monty.h"

/**
 * pint - idk
 *
 * @stack: idk
 * @line_num: idk
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);

}
