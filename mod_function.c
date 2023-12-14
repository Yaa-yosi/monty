#include "monty.h"
/**
 * mod - computes the remainder of the division of the second element
 * by the top element of the stack.
 * @head: double pointer to stack
 * @line_no: line number
 */
void mod(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int count = 0, modulo;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	modulo = tmp->next->n % tmp->n;
	tmp->next->n = modulo;
	pop(head, line_no);
	*head = tmp->next;
}
