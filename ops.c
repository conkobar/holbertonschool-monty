#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, n;
	stack_t *tmp;

	if (!ops[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(1);
	}

	for (i = 0; ops[1][i]; i++)
	{
		if ((ops[1][i] == '-' && i == 0))
			i++;

		if (!isdigit(ops[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(1);
		}
	}

	n = atoi(ops[1]);

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "L%d: usage: tmp malloc error; push integer\n", line_number);
		exit(1);
	}

	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}


/**
 * pall - prints all values of stack, starting from the top
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->prev)
			tmp = tmp->prev;

		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
