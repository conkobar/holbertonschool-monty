#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: current line number of .m file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = ops[0];
	int data, i;
	stack_t *new;

	if (!arg)
		errorlocus(4, line_number);

	for (i = 0; arg[i]; i++)
	{
		if ((isdigit(arg[i])) == 0 && arg[i] != '-')
			errorlocus(4, line_number);
	}

	data = atoi(arg);

	new = malloc(sizeof(stack_t));
	if (!new)
		errorlocus(4, line_number);

	new->n = data;
	new->prev = NULL;
	new->next = *stack;

	if (!*stack)
		(*stack)->prev = new;

	*stack = new;
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
