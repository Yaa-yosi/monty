#include "monty.h"
/**
 * free_stack - free a stack
 * @head: pointer to first node
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
