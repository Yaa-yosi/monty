#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @head: double pointer to stack
 * @line_no: line number
 */
void rotr(stack_t **head, unsigned int line_no)
{
	stack_t *tmp, *tmp2;
	(void)line_no;

	if (*head == NULL || (*head)->next == NULL)
		return;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = tmp->prev;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = (*head)->next;
	tmp2->next = NULL;
	*head = tmp;
}
