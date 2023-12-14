#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: double pointer to stack
 * @line_no: line number
 */
void rotl(stack_t **head, unsigned int line_no)
{
	stack_t *tmp, *tmp2;
	(void)line_no;

	if (*head == NULL || (*head)->next == NULL)
		return;

	tmp = *head;
	tmp2 = (*head)->next;
	tmp2->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	*head = tmp2;
}
