#include "monty.h"

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%i\n", tmp->n);

			if (tmp->next)
				tmp = tmp->next;
		}
		free(tmp);
	}


}
