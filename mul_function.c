#include "monty.h"
/**
 * mul - multiplies the top two elements of the stack.
 * @head: double pointer to stack
 * @line_no: line number
 */
void mul(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int count = 0, product;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	product = tmp->n * tmp->next->n;
	tmp->next->n = product;
	*head = tmp->next;
	free(tmp);
}
