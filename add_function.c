#include "monty.h"
/**
 * add - swaps the top two elements of the stack.
 * @head: double pointer to head
 * @line_no: line number
 */
void add(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int count = 0, sum;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	pop(head, line_no);
	*head = tmp->next;
}
