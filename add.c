#include "monty.h"

/**
 * add - add the top two elements together
 * @stack: pointer to the head node of stack
 * @line_number: the line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	newnode = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(newnode);
}
