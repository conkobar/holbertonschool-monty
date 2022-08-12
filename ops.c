#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void push(stack_t **stack, unsigned int line_number)
{
	unsigned int i;

	if (!ops[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		ops[3] = "err";
		return;
	}

	for (i = 0; ops[1][i] != '\0'; i++)
	{
		if ((ops[1][i] == '-' && i == 0) || (ops[1][i] == '.'))
			i++;

		if (!isdigit(ops[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			ops[3] = "err";
			return;
		}
	}
}


/**
 * pall - prints all values of stack, starting from the top
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;

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
