#include "monty.h"
/**
 * sub - subtracts the top element from the second element of the stack.
 * @head: double pointer to head
 * @line_no: line number
 */
void sub(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int count = 0, remainder;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	remainder = tmp->next->n - tmp->n;
	tmp->next->n = remainder;
	pop(head, line_no);
	*head = tmp->next;
}
