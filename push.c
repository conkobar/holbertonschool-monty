#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
	char *ARG = arg.argument;
	int data, i;
	stack_t *element;

	if (!ARG)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; ARG[i]; i++)
	{
		if ((isdigit(ARG[i])) == 0 && ARG[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}

	data = atoi(ARG);

	element = malloc(sizeof(stack_t));
	if (!element)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	element->n = data;
	element->prev = NULL;
	element->next = *stack;

	if (!*stack)
		(*stack)->prev = element;

	*stack = element;
}
