#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!ops[1])
		return;
	for (n = 0; ops[1][n] != '\0'; n++)
	{
		if ((!n && ops[1][n] == '-') || (ops[1][n] == '.'))
			continue;

		if (!isdigit(ops[1][n]))
		{
			ops[3] = "no digit";
			return;
		}
	}

	n = atoi(ops[1]);

	if (!so_head(stack, n))
	{
		ops[3] = "head";
		return;
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
