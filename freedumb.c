#include "monty.h"

/**
 * freedumb - frees your head
 * @head: your head
 */
void freedumb(stack_t *head)
{
	stack_t *tmp, *new;

	if (!head)
		return;

	new = head;

	while (new->prev)
		new = new->prev;

	while (new)
	{
		tmp = new;
		new = new->next;
		free(tmp);
	}
}
